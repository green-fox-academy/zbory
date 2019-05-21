#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	int freq_state = 1;
	int period_time = 2000;

	while (1) {
		for (int i = 0; i < 3; i++) {
			BSP_LED_On(LED1);
			HAL_Delay(period_time);
			BSP_LED_Off(LED1);
			HAL_Delay(period_time);
		}
		if (freq_state) {
			period_time /= 2;
			if(period_time == 250)
				freq_state = 0;
		}
		else{
			period_time *=2;
			if(period_time == 2000)
				freq_state = 1;
		}
	}
}

