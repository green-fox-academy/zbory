#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>

GPIO_InitTypeDef railroad_leds;

void init_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE(); /* GPIOI clock enable */

	// Init user led (A 1-4)
	railroad_leds.Pin = (GPIO_PIN_7 | GPIO_PIN_8);
	railroad_leds.Mode = GPIO_MODE_OUTPUT_PP;
	railroad_leds.Pull = GPIO_NOPULL;
	railroad_leds.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &railroad_leds);

}

int main(void)
{
	HAL_Init();
	init_pins();

	int state = 0;

	while (1) {

		if (state) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 0);
			HAL_Delay(400);
			state = 0;
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, 0);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 1);
			HAL_Delay(400);
			state = 1;
		}

	}
}
