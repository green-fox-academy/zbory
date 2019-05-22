#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>



void set_led_value(uint16_t *red_value, uint16_t *green_value, int *state)
{
	switch (*state) {
	case 0:
		*red_value = *red_value << 1;
		if (*red_value == 1024) {
			*state = 3;
		}
		break;
	case 1:
		*green_value = *green_value << 1;
		if (*green_value == 128) {
			*state = 2;
		}
		break;
	case 2:
		*green_value = *green_value >> 1;
		if (*green_value == 32) {
			*state = 0;
			*green_value = 0;
			*red_value = 128;
		}
		break;
	case 3:
		*red_value = *red_value >> 1;
		if (*red_value == 64) {
			*state = 1;
			*red_value = *red_value = 0;
			*green_value = 64;
		}
		break;
	}

}

void init_pins()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

// Init user led (A 1-4)
	GPIOF->MODER |= (GPIO_MODER_MODER7_0); /* configure PA1 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	GPIOG->MODER |= (GPIO_MODER_MODER6_0); //G6, G7
	GPIOG->MODER |= (GPIO_MODER_MODER7_0);

	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7); /* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_6);
	GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_7);

	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10);
	GPIOG->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR6);
	GPIOG->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7);

	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR7); /* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);
	GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR6);
	GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR7);

}

int main(void)
{
	HAL_Init();
	init_pins();

	uint16_t red_led_data = 0;
	uint16_t green_led_data = 0;
	red_led_data = 1 << 6;

	int state = 0;

	uint32_t user_button = (1 << 4);
	int button_down = 0;

	while (1) {

		/* If button is pressed do something */
//	if (GPIOB->IDR & (user_button) && button_down == 0) {
//		if (!(red_led_data == 1024 || red_led_data == 128))
//			direction = !direction;
//		button_down = 1;
//	}
//	if (!(GPIOB->IDR & (user_button))) {
//		button_down = 0;
//	}
		GPIOF->BSRR = red_led_data;
		GPIOG->BSRR = green_led_data;

		HAL_Delay(125);

		GPIOF->BSRR = red_led_data << 16;
		GPIOG->BSRR = green_led_data << 16;

		set_led_value(&red_led_data, &green_led_data, &state);

	}
}
