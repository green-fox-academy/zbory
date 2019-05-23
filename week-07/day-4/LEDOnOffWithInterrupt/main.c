#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef railroad_leds;
int led_state = 0;

void init_user_button()
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

void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	/* GPIOI clock enable */

	// Init user led (A 1-4)
	railroad_leds.Pin = (GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10);
	railroad_leds.Mode = GPIO_MODE_OUTPUT_PP;
	railroad_leds.Pull = GPIO_NOPULL;
	railroad_leds.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &railroad_leds);

}

int main(void)
{
	HAL_Init();
	init_pins();
	init_user_button();

	while (1) {

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
	if (!led_state) {
		GPIOF->BSRR = 15 << 7;
		led_state = 1;
	} else {
		GPIOF->BSRR = 15 << 23;
		led_state = 0;
	}
}

