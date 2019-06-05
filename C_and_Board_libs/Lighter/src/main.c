#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "timer.h"
#include "gpio_pin.h"
#include "systemclock_init.h"

uint8_t gas_state = 0;
volatile uint8_t empty = 0;
volatile uint8_t flame = 0;
uint32_t gas_counter;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	A1_GPIO_input(GPIO_INPUT);
	A5_GPIO_output_init();
	user_button_init(GPIO_INPUT_IT);
	init_timer3(TIMER_IT);
	__HAL_TIM_SET_COUNTER(&timer3_handle, 40000);

	while (1) {
		gas_counter = __HAL_TIM_GET_COUNTER(&timer3_handle);

		if (!empty) {
			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10) && !gas_state) {
				gas_state = 1;
				HAL_TIM_Base_Start_IT(&timer3_handle);

			}
			if (!HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10) && gas_state) {
				HAL_TIM_Base_Stop_IT(&timer3_handle);
				gas_state = 0;
			}

			if (gas_state && flame) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, 1);
			} else {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, 0);
				flame = 0;
			}
		}
		else{
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, 0);
			flame = 0;
		}
	}
}

//Interrupt handler and callback
void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	flame = 1;
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer3_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM3) {
		empty = 1;
	}
}

