#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */

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

	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR7); /* ensure all pull up pull down resistors are disabled */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

}

int main(void)
{
	HAL_Init();
	init_pins();

	while (1) {

		int a = 0;

		GPIOF->BSRR = GPIO_BSRR_BS_7;
		GPIOF->BSRR = GPIO_BSRR_BS_8;
		GPIOF->BSRR = GPIO_BSRR_BS_9;
		GPIOF->BSRR = GPIO_BSRR_BS_10;

		for (int i = 0; i < 200000; i++) {
			a = i;
		}

		GPIOF->BSRR = GPIO_BSRR_BR_7;
		GPIOF->BSRR = GPIO_BSRR_BR_8;
		GPIOF->BSRR = GPIO_BSRR_BR_9;
		GPIOF->BSRR = GPIO_BSRR_BR_10;

		for (int i = 0; i < 200000; i++) {
			a = i;
		}

	}
}
