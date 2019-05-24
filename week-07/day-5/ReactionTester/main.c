#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

GPIO_InitTypeDef user_button_handle;
RNG_HandleTypeDef randomNumber;

uint32_t tickstart = 0;
uint32_t tickend = 0;
uint32_t total_time = 0;
uint8_t draw_result = 0;
uint8_t result = 0;
char number[3] = { 0, 0, 0 };

void button_init()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11; /* the user button has a built-in resistor: */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button_handle);

	/* assign a priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void LCD_Init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
}

void random_init()
{
	__HAL_RCC_RNG_CLK_ENABLE()
	;
	randomNumber.Instance = RNG;

	HAL_RNG_Init(&randomNumber);
}
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	LCD_Init();
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	button_init();
	random_init();
	uint32_t delay_time;

	while (1) {

		int tries = 3;
		for (int i = 0; i < tries; i++) {

			BSP_LCD_Clear(LCD_COLOR_WHITE);
			draw_result = 0;
			delay_time = HAL_RNG_GetRandomNumber(&randomNumber) % 7000;

			/* drawing text */
			BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
			BSP_LCD_DisplayStringAt(20, 50,
					"Push my button when the spot appears! ;)", CENTER_MODE);

			/* drawing a red circle */
			HAL_Delay(250 + delay_time);

			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_FillCircle(50, 50, 30);
			tickstart = HAL_GetTick();
			HAL_Delay(3000);
		}
		BSP_LCD_Clear(LCD_COLOR_WHITE);
		sprintf(number, "Your average: %.2f seconds", total_time / 1000.0f / tries);
		BSP_LCD_DisplayStringAt(20, 50, number, CENTER_MODE);
		HAL_Delay(5000);
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* this is the place for the user code */
	tickend = HAL_GetTick();
	uint32_t delta = tickend - tickstart;
	if (tickend - tickstart > 1000)
		BSP_LCD_DisplayStringAt(20, 70, "Too slow! You don't love me!",
				CENTER_MODE);
	else
		BSP_LCD_DisplayStringAt(20, 70, "GRRRR... I like it!", CENTER_MODE);
	total_time += delta;
	sprintf(number, "%.2f seconds", delta / 1000.0f);
	BSP_LCD_DisplayStringAt(20, 90, number, CENTER_MODE);

}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
