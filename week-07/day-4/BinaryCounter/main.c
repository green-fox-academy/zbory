#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>

GPIO_InitTypeDef railroad_leds;

void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	; /* GPIOI clock enable */

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

	while (1) {

		led_value = (led_value + 1) % 16;
		GPIOF->BSRR = led_value << 7;
		HAL_Delay(500);
		GPIOF->BSRR = led_value << 23;


	}
}
