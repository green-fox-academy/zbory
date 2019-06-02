#include "stm32f7xx.h"
#include "uart.h"

void init_usart1()
{
	GPIO_InitTypeDef GPIOTx_handle;
	GPIO_InitTypeDef GPIORx_handle;

	/* enable GPIO clock */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	/* configure GPIO for UART transmit line */
	GPIOTx_handle.Pin = GPIO_PIN_9;
	GPIOTx_handle.Mode = GPIO_MODE_AF_PP;
	GPIOTx_handle.Pull = GPIO_NOPULL;
	GPIOTx_handle.Speed = GPIO_SPEED_FAST;
	GPIOTx_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTx_handle);

	/* configure GPIO for UART receive line */
	GPIORx_handle.Pin = GPIO_PIN_7;
	GPIORx_handle.Mode = GPIO_MODE_AF_PP;
	GPIORx_handle.Pull = GPIO_NOPULL;
	GPIORx_handle.Speed = GPIO_SPEED_FAST;
	GPIORx_handle.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORx_handle);

	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	/* defining the UART configuration structure */
	usart1_handle.Instance = USART1;
	usart1_handle.Init.BaudRate = 115200;
	usart1_handle.Init.WordLength = UART_WORDLENGTH_8B;
	usart1_handle.Init.StopBits = UART_STOPBITS_1;
	usart1_handle.Init.Parity = UART_PARITY_NONE;
	usart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	usart1_handle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&usart1_handle);

	/* enable interrupt */
	HAL_NVIC_SetPriority(USART1_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}
