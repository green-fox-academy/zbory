#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	int button_count;
	int flashing = 0;
	int button_down = 0;

	while (1) {
		/* If button is pressed do something */
		if (BSP_PB_GetState(BUTTON_KEY) == 1 && button_down == 0) {
			button_count++;
			if (button_count == 5)
				flashing = 1;
			button_down = 1;
		}
		if (BSP_PB_GetState(BUTTON_KEY) == 0) {
			button_down = 0;
		}
		if (flashing) {
			BSP_LED_On(LED1);
			HAL_Delay(250);
			BSP_LED_Off(LED1);
			HAL_Delay(250);
		}
	}
}

