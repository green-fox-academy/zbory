#include "stm32f7xx.h"
#include "timer.h"

/*********************** TIMER Init ***********************/

void init_timer2(TimerMode mode)
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer2_handle.Instance = TIM2;
	timer2_handle.Init.Prescaler = 108 - 1; // 0.001ms
	timer2_handle.Init.Period = 100 - 1; // 0.1ms
	timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	switch (mode) {
	case TIMER_BASE:
		HAL_TIM_Base_Init(&timer2_handle);
		break;
	case TIMER_IT:
		HAL_TIM_Base_Init(&timer2_handle);
		__HAL_TIM_CLEAR_FLAG(&timer2_handle, TIM_SR_UIF);
		/* enable interrupt */
		HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
		break;
	case TIMER_PWM:
		HAL_TIM_PWM_Init(&timer2_handle);
		init_PWM2();
		break;

	}
}

void init_timer3(TimerMode mode)
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	timer3_handle.Instance = TIM3;
	timer3_handle.Init.Prescaler = 54000 - 1; // 0.5ms
	timer3_handle.Init.Period = 200 - 1; // 1s
	timer3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	switch (mode) {
	case TIMER_BASE:
		HAL_TIM_Base_Init(&timer3_handle);
		break;
	case TIMER_IT:
		HAL_TIM_Base_Init(&timer3_handle);
		__HAL_TIM_CLEAR_FLAG(&timer3_handle, TIM_SR_UIF);
		/* enable interrupt */
		HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
		break;
	case TIMER_PWM:
		HAL_TIM_PWM_Init(&timer3_handle);
		init_PWM3();
		break;

	}
}

void init_timer12(TimerMode mode)
{
	__HAL_RCC_TIM12_CLK_ENABLE()
	;

	timer12_handle.Instance = TIM12;
	timer12_handle.Init.Prescaler = 10800 - 1; // 0.1ms
	timer12_handle.Init.Period = 10000 - 1; // 1s
	timer12_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer12_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	switch (mode) {
	case TIMER_BASE:
		HAL_TIM_Base_Init(&timer12_handle);
		break;
	case TIMER_IT:
		HAL_TIM_Base_Init(&timer12_handle);
		__HAL_TIM_CLEAR_FLAG(&timer12_handle, TIM_SR_UIF);
		/* enable interrupt */
		HAL_NVIC_SetPriority(TIM8_BRK_TIM12_IRQn, 3, 0);
		HAL_NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
		break;
	case TIMER_PWM:
		HAL_TIM_PWM_Init(&timer12_handle);
		init_PWM12();
		break;

	}
}

/*********************** PWM Init ***********************/

void init_PWM2()
{
	pwm2_config.Pulse = 100;
	pwm2_config.OCMode = TIM_OCMODE_PWM1;
	pwm2_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm2_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer2_handle, &pwm2_config, TIM_CHANNEL_1);
}

void init_PWM3()
{
	pwm3_config.Pulse = 50;
	pwm3_config.OCMode = TIM_OCMODE_PWM1;
	pwm3_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm3_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer3_handle, &pwm3_config, TIM_CHANNEL_1);
}

void init_PWM12()
{
	pwm12_config.Pulse = 50;
	pwm12_config.OCMode = TIM_OCMODE_PWM1;
	pwm12_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm12_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer12_handle, &pwm12_config, TIM_CHANNEL_1);
}

