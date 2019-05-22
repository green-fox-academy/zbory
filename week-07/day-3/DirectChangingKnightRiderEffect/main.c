#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdint.h>

void init_pins()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	// Init user led (A 1-4)
	GPIOF->MODER |= (GPIO_MODER_MODER7_0); /* configure PA1 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->MODER |= (GPIO_MODER_MODER10_0);

	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7); /* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);

	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10);

	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR7); /* ensure all pull up pull down resistors are disabled */
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR8);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR9);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

}

int main(void)
{
	HAL_Init();
	init_pins();


	uint16_t led_data = 0;
	uint8_t direction = 1;
	led_data = 1 << 6;

	uint32_t user_button = (1 << 4);
	int button_down = 0;

	while (1) {

		/* If button is pressed do something */
		if (GPIOB->IDR & (user_button) && button_down == 0) {
			if(!(led_data == 1024 || led_data == 128))
			direction = !direction;
			button_down = 1;
		}
		if (!(GPIOB->IDR & (user_button))) {
			button_down = 0;
		}
		GPIOF->BSRR = led_data;

		HAL_Delay(500);

		GPIOF->BSRR = led_data << 16;

		if (direction) {
			led_data = led_data << 1;
			if (led_data == 1024)
				direction = !direction;
		} else {
			led_data = led_data >> 1;
			if (led_data == 128)
				direction = !direction;

		}
	}
}
