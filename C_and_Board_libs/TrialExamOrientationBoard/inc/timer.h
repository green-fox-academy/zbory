#ifndef TEMPLATE_TIMER_H
#define TEMPLATE_TIMER_H

/* Initializing timers:
 * -	HAL_TIM_Base_Init()
 * -	HAL_TIM_PWM_Init()
 *
 * Starting timer:
 * -    HAL_TIM_Base_Start()
 * -	HAL_TIM_Base_Start_IT()
 * - 	HAL_TIM_PWM_Start()
 *
 *Get/Set timer value:
 * -    __HAL_TIM_GET_COUNTER()
 * -    __HAL_TIM_SET_COUNTER()
 * -    __HAL_TIM_SET_COMPARE()
 */

typedef enum timer_mode{
	TIMER_BASE,
	TIMER_IT,
	TIMER_PWM
} TimerMode;

TIM_HandleTypeDef timer2_handle;
TIM_HandleTypeDef timer3_handle;
TIM_HandleTypeDef timer12_handle;

TIM_OC_InitTypeDef pwm2_config;
TIM_OC_InitTypeDef pwm3_config;
TIM_OC_InitTypeDef pwm12_config;

void init_timer2(TimerMode mode);
void init_timer3(TimerMode mode);
void init_timer12(TimerMode mode);

void init_PWM2();
void init_PWM3();
void init_PWM12();

#endif /* TEMPLATE_TIMER_H */
