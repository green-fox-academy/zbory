#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "systemclock_init.h"
#include "timer.h"
#include "gpio_pin.h"

typedef enum state {
	OPEN, SECURING, SECURED, OPENING
} State;

uint32_t previous_button_push = 0;
uint16_t debounce_time = 500;
uint8_t led_state = 1;
State state = OPEN;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);

	init_timer2(TIMER_IT); // Init timer2 for flashing green LED
	init_timer3(TIMER_IT); // Init timer3 for waiting 5,6 seconds
	user_button_init(GPIO_INPUT_IT); // Init user button
	A5_GPIO_output_init(); // Init A5 pin as output for debugging

	BSP_LED_On(LED_GREEN);
	HAL_TIM_Base_Start_IT(&timer2_handle); // Starting timer2 for flashing green LED

	while (1) {
		if (state == OPEN) {
			HAL_TIM_Base_Stop_IT(&timer3_handle); // Stopping timer3
			__HAL_TIM_SET_COUNTER(&timer3_handle, 1); // Resetting timer3 counter

			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); // Re-Enable button interrupt
			__HAL_TIM_SET_AUTORELOAD(&timer2_handle, 10000); // Setting timer2 for 0.5 Hz flashing
		}
		if (state == SECURING) {
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn); // Disable button interrupt

			//__HAL_TIM_SET_COUNTER(&timer2_handle, 1); // Resetting timer2 COUNTER in case it stopped above 5000
			__HAL_TIM_SET_AUTORELOAD(&timer2_handle, 5000); // Setting timer2 for 1 Hz flashing

			__HAL_TIM_SET_AUTORELOAD(&timer3_handle, 10000); // Setting timer3 for 5 seconds wait
			HAL_TIM_Base_Start_IT(&timer3_handle); // Starting timer3
		}
		if (state == SECURED) {
			HAL_TIM_Base_Stop_IT(&timer3_handle); // Stopping timer3
			__HAL_TIM_SET_COUNTER(&timer3_handle, 1); // Resetting timer3 counter
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); // Re-Enable button interrupt
			HAL_NVIC_DisableIRQ(TIM2_IRQn); // Disable LED flashing
			BSP_LED_Off(LED_GREEN); // Making sure LED is off
		}
		if (state == OPENING) {
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn); // Disable button interrupt
			HAL_NVIC_EnableIRQ(TIM2_IRQn); // Re-Enable LED flashing
			__HAL_TIM_SET_AUTORELOAD(&timer3_handle, 12000); // Setting timer3 for 6 seconds wait
			HAL_TIM_Base_Start_IT(&timer3_handle); // Starting timer3
		}
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (HAL_GetTick() - previous_button_push > debounce_time) {
		previous_button_push = HAL_GetTick();
		// Changing states according to user button presses
		if (state == OPEN) {
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
			state = SECURING;
		}

		if (state == SECURED) {
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
			state = OPENING;
		}
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
		} else {
			BSP_LED_On(LED_GREEN);
			led_state = 1;
		}
	}

	// Stopping and resetting the timer after SECURING and OPENING states
	if (htim->Instance == TIM3) {
		// Changing states after wait is over
		if (state == SECURING) {
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
			state = SECURED; // Stepping into SECURED state
		}
		if (state == OPENING) {
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
			state = OPEN; // Stepping into OPEN state
		}
	}
}
