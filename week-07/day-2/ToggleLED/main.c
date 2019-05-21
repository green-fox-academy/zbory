#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	int state = 0;
	int button_down = 0;

	while (1) {
		/* If button is pressed do something */
		if (BSP_PB_GetState(BUTTON_KEY) == 1 && button_down == 0) {
			state = ++state % 3;
			button_down = 1;
		}
		if (BSP_PB_GetState(BUTTON_KEY) == 0) {
			button_down = 0;
		}
		switch (state) {
		case 0:
			BSP_LED_Off(LED1);
			break;
		case 1:
			BSP_LED_On(LED1);
			break;
		case 2:
			BSP_LED_On(LED1);
			HAL_Delay(125);
			BSP_LED_Off(LED1);
			HAL_Delay(125);
			break;
		}
	}
}

