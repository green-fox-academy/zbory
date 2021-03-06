#include <stdio.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "systemclock_init.h"

GPIO_InitTypeDef user_button_handle;

GPIO_InitTypeDef gpiopwm_config;
/* the timer's config structure */
TIM_HandleTypeDef timer2_handle;
/* the output compare channel's config structure */
TIM_OC_InitTypeDef pwm_config;

void init_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11; /* the user button has a built-in resistor: */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button_handle);

	/* assign a priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void PWM_Pin_init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	gpiopwm_config.Pin = GPIO_PIN_15;
	gpiopwm_config.Mode = GPIO_MODE_AF_PP;
	gpiopwm_config.Pull = GPIO_NOPULL;
	gpiopwm_config.Speed = GPIO_SPEED_FAST;
	gpiopwm_config.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &gpiopwm_config);
}

void init_timer2()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer2_handle.Instance = TIM2;
	timer2_handle.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
	timer2_handle.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
	timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer2_handle);
}

void init_PWM()
{
	/*
	 * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
	 * our eyes are not able to notice that it is a vibrating light
	 */
	pwm_config.Pulse = 0;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer2_handle, &pwm_config, TIM_CHANNEL_1);
}

uint32_t previous_push = 0;
float duty_cycle = 0;

int main(void)
{
	HAL_Init();

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();
	init_timer2();
	init_PWM();
	init_button();
	PWM_Pin_init();

	/* starting the timer */
	HAL_TIM_PWM_Start(&timer2_handle, TIM_CHANNEL_1);

	while (1) {

		// We can set the compare value (the pulse width of the signal) like this:
		__HAL_TIM_SET_COMPARE(&timer2_handle, TIM_CHANNEL_1, duty_cycle);
		if (duty_cycle > 0)
			duty_cycle -= 0.0001;
		else
			duty_cycle = 0;

	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	int now = HAL_GetTick();
	if (previous_push != 0) {
		if ((now - previous_push) / 10 < 100)
			duty_cycle = 100 - (now - previous_push) / 10;
		else
			duty_cycle = 0;
	}
	previous_push = now;
}
