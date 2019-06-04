#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "systemclock_init.h"
#include "timer.h"
#include "gpio_pin.h"
#include "uart.h"

typedef enum state {
	OPEN, SECURING, SECURED, OPENING
} State;

uint8_t led_state = 1;
State state = OPEN;

uint32_t timer2_cnt;
uint32_t timer2_arr;
uint32_t timer3_cnt;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_usart1();
	BSP_LED_Init(LED_GREEN);

	init_timer2(TIMER_IT); // Init timer2 for flashing green LED
	init_timer3(TIMER_IT); // Init timer3 for waiting 5 and 6 seconds
	user_button_init(GPIO_INPUT_IT); // Init user button

	BSP_LED_On(LED_GREEN);
	HAL_TIM_Base_Start_IT(&timer2_handle); // Starting timer2 for flashing green LED

	while (1) {
		timer2_cnt = __HAL_TIM_GET_COUNTER(&timer2_handle);
		timer3_cnt = __HAL_TIM_GET_COUNTER(&timer3_handle);
		timer2_arr = __HAL_TIM_GET_AUTORELOAD(&timer2_handle);

		if (state == OPEN) {
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); // Re-Enable button interrupt
			__HAL_TIM_SET_AUTORELOAD(&timer2_handle, 10000); // Setting timer2 for 0.5 Hz flashing
		}
		if (state == SECURING) {
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn); // Disable button interrupt

		}
		if (state == SECURED) {
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); // Re-Enable button interrupt
			BSP_LED_Off(LED_GREEN); // Making sure LED is off
		}
		if (state == OPENING) {
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn); // Disable button interrupt
			HAL_NVIC_EnableIRQ(TIM2_IRQn); // Re-Enable LED flashing

		}
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	// Changing states according to user button presses
	if (state == OPEN) {
		__HAL_TIM_SET_AUTORELOAD(&timer2_handle, 5000); // Setting timer2 for 1 Hz flashing
		__HAL_TIM_SET_COUNTER(&timer2_handle, 1); // Resetting timer2 COUNTER in case it stopped above 5000

		HAL_UART_Transmit(&usart1_handle, "Entered SECURING state\r\n", 24,
				0xFFFF);

		__HAL_TIM_SET_AUTORELOAD(&timer3_handle, 10000); // Setting timer3 for 5 seconds wait
		HAL_TIM_Base_Start_IT(&timer3_handle); // Starting timer3
		state = SECURING;
		return;
	}

	if (state == SECURED) {
		HAL_UART_Transmit(&usart1_handle, "Entered OPENING state\r\n", 23,
				0xFFFF);
		__HAL_TIM_SET_AUTORELOAD(&timer3_handle, 12000); // Setting timer3 for 6 seconds wait
		HAL_TIM_Base_Start_IT(&timer3_handle); // Starting timer3

		HAL_TIM_Base_Start_IT(&timer2_handle); // Starting timer2
		state = OPENING;
		return;
	}

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer2_handle);
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer3_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	// Flashing the green LED
	if (htim->Instance == TIM2) {
		if (led_state) {
			BSP_LED_Off(LED_GREEN);
			led_state = 0;
			HAL_UART_Transmit(&usart1_handle, "LED state: OFF\r\n", 16, 0xFFFF);
		} else {
			BSP_LED_On(LED_GREEN);
			led_state = 1;
			HAL_UART_Transmit(&usart1_handle, "LED state: ON\r\n", 15, 0xFFFF);
		}
		return;
	}

	// Changing states after wait is over
	if (htim->Instance == TIM3) {
		__HAL_TIM_SET_COUNTER(&timer3_handle, 1);
		HAL_TIM_Base_Stop_IT(&timer3_handle); // Stopping timer3

		if (state == SECURING) {
			HAL_UART_Transmit(&usart1_handle, "Entered SECURED state\r\n", 23,
					0xFFFF);
			state = SECURED; // Stepping into SECURED state

			__HAL_TIM_SET_COUNTER(&timer2_handle, 1);
			HAL_TIM_Base_Stop_IT(&timer2_handle); // Stopping timer2
		}
		if (state == OPENING) {
			HAL_UART_Transmit(&usart1_handle, "Entered OPEN state\r\n", 20,
					0xFFFF);
			state = OPEN; // Stepping into OPEN state
		}
		return;
	}
}
