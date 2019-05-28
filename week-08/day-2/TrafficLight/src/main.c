#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "systemclock_init.h"

GPIO_InitTypeDef gpio_config;
/* the timer's config structure */
TIM_HandleTypeDef timer2_handle;

void GPIO_init()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	; /* GPIOI clock enable */

	// Init user led (A 1-4)
	gpio_config.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer2_handle.Instance = TIM2;
	timer2_handle.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer2_handle.Init.Period = 40000 - 1; // 10000 x 0.1 ms = 1 second period
	timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer2_handle);
}

uint16_t timer_value = 0;

int main(void)
{
	HAL_Init();

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();
	GPIO_init();
	init_timer();

	/* starting the timer */
	HAL_TIM_Base_Start(&timer2_handle);

	while (1) {

		//blinking the user LED with 1 Hz (1 on and 1 off per seconds)
		timer_value = __HAL_TIM_GET_COUNTER(&timer2_handle);
		if (timer_value == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		}
		if (timer_value == 10000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		}
		if (timer_value == 20000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		}
		if (timer_value == 30000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		}
	}
}
