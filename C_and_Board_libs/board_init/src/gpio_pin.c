#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "gpio_pin.h"


/*********************** User button Init ***********************/
void user_button_init(GPIOMode mode)
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL; /* the user button has a built-in resistor: */
	user_button_handle.Speed = GPIO_SPEED_FAST;
	if (mode == GPIO_INPUT_IT) {
		user_button_handle.Mode = GPIO_MODE_IT_RISING;
	} else {
		user_button_handle.Mode = GPIO_MODE_INPUT;
	}
	HAL_GPIO_Init(GPIOI, &user_button_handle);

	if (mode == GPIO_INPUT_IT) {
		/* assign a priority to our interrupt line */
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
		/* tell the interrupt handling unit to process our interrupts */
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	}
}

//Interrupt handler and callback
//void EXTI15_10_IRQHandler(){HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);}
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){}

/*********************** A5 Output Init ***********************/

void A5_GPIO_output_init()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	A5_GPIO_output_handle.Pin = GPIO_PIN_6;
	A5_GPIO_output_handle.Pull = GPIO_NOPULL; /* external pull up resistor required */
	A5_GPIO_output_handle.Speed = GPIO_SPEED_FAST;
	A5_GPIO_output_handle.Mode = GPIO_MODE_OUTPUT_PP;

	HAL_GPIO_Init(GPIOF, &A5_GPIO_output_handle);
}

/*********************** D9 PWM Output Init ***********************/

void D9_GPIO_pwm_output_init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	D9_GPIO_pwm_output_handle.Pin = GPIO_PIN_15;
	D9_GPIO_pwm_output_handle.Mode = GPIO_MODE_AF_PP;
	D9_GPIO_pwm_output_handle.Pull = GPIO_NOPULL;
	D9_GPIO_pwm_output_handle.Speed = GPIO_SPEED_FAST;
	D9_GPIO_pwm_output_handle.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &D9_GPIO_pwm_output_handle);
}

/*********************** A0 Analogue Output Init ***********************/

void A0_GPIO_analogue_input_init(){
	{
		/* configuring A0 pin as analog input */
		__HAL_RCC_GPIOA_CLK_ENABLE()
		;
		/* there is no need for setting the Alternate datafield like other peripherals*/
		A0_GPIO_analogue_input_handle.Mode = GPIO_MODE_ANALOG;
		A0_GPIO_analogue_input_handle.Pin = GPIO_PIN_0;
		A0_GPIO_analogue_input_handle.Speed = GPIO_SPEED_FAST;
		A0_GPIO_analogue_input_handle.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(GPIOA, &A0_GPIO_analogue_input_handle);
	}
}

/*********************** A1 Input Init ***********************/

void A1_GPIO_input(GPIOMode mode)
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	A1_GPIO_input_handle.Pin = GPIO_PIN_10;
	A1_GPIO_input_handle.Pull = GPIO_NOPULL;
	A1_GPIO_input_handle.Speed = GPIO_SPEED_FAST;
	if (mode == GPIO_INPUT_IT) {
		A1_GPIO_input_handle.Mode = GPIO_MODE_IT_RISING;
	} else {
		A1_GPIO_input_handle.Mode = GPIO_MODE_INPUT;
	}
	HAL_GPIO_Init(GPIOF, &A1_GPIO_input_handle);

	if (mode == GPIO_INPUT_IT) {
		/* assign a priority to our interrupt line */
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
		/* tell the interrupt handling unit to process our interrupts */
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	}
}
