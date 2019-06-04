#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "timer.h"
#include "systemclock_init.h"
#include "gpio_pin.h"
#include "adc.h"

typedef enum settings_mode {
	TIME, BRIGHTNESS
} Mode;

Mode mode = BRIGHTNESS;
uint8_t led_state = 1;

uint32_t timer_arr;
uint32_t timer_cnt;
int adc_val;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	D9_GPIO_pwm_output_init();
	init_timer2(TIMER_PWM);
	init_ADC3();
	A0_GPIO_analogue_input_init();
	HAL_TIM_PWM_Start(&timer2_handle, TIM_CHANNEL_1);
	init_timer3(TIMER_IT);
	HAL_TIM_Base_Start_IT(&timer3_handle);
	user_button_init(GPIO_INPUT_IT);


	while (1) {

		HAL_Delay(50);
		HAL_ADC_Start(&adc3_handle);
		if (HAL_ADC_PollForConversion(&adc3_handle, 10) == HAL_OK) {
			adc_val = HAL_ADC_GetValue(&adc3_handle);
			if (mode == BRIGHTNESS) {
				__HAL_TIM_SET_COMPARE(&timer2_handle, TIM_CHANNEL_1,
						(adc_val / 4095.0f) * 100.0f);
			}
			else {
				timer_cnt = __HAL_TIM_GET_COUNTER(&timer3_handle);
				timer_arr = __HAL_TIM_GET_COUNTER(&timer3_handle) > 100 * (1 + adc_val / 4095.0f * 19.0f) ?
						__HAL_TIM_GET_COUNTER(&timer3_handle) :
						100 * (1 + adc_val / 4095.0f * 19.0f);
				__HAL_TIM_SET_AUTORELOAD(&timer3_handle, timer_arr);
			}
		}
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(mode == BRIGHTNESS)
		mode = TIME;
	else
		mode = BRIGHTNESS;
}

void TIM3_IRQHandler(){
	HAL_TIM_IRQHandler(&timer3_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(led_state){
		HAL_TIM_PWM_Stop(&timer2_handle, TIM_CHANNEL_1);
		led_state = 0;
	}
	else{
		HAL_TIM_PWM_Start(&timer2_handle, TIM_CHANNEL_1);
		led_state = 1;
	}
}

