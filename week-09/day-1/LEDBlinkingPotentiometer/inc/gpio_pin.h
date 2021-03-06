#ifndef TEMPLATE_GPIO_PIN_H
#define TEMPLATE_GPIO_PIN_H

typedef enum gpio_mode{
	GPIO_INPUT,
	GPIO_INPUT_IT,
	GPIO_OUTPUT,
	GPIO_PWM
} GPIOMode;

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef A5_GPIO_output_handle;
GPIO_InitTypeDef D9_GPIO_pwm_output_handle;
GPIO_InitTypeDef A0_GPIO_analogue_input_handle;

void user_button_init(GPIOMode mode);
void A5_GPIO_output_init();
void D9_GPIO_pwm_output_init();
void A0_GPIO_analogue_input_init();

#endif /* TEMPLATE_GPIO_PIN_H */
