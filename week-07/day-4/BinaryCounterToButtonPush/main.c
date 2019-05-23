#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>

GPIO_InitTypeDef railroad_leds;

void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE(); /* GPIOI clock enable */
	__HAL_RCC_GPIOB_CLK_ENABLE(); 

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

	int led_value = 0;
	int button_down = 0;

	while (1) {

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) && button_down == 0) {
			GPIOF->BSRR = led_value << 23;
			led_value += 1;
			GPIOF->BSRR = led_value << 7;
			button_down = 1;
		}
		if (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4))
			button_down = 0;

	}
}
