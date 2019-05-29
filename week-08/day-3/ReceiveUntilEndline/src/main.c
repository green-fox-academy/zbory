#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "systemclock_init.h"

UART_HandleTypeDef uart_handle;

void init_uart()
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
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&uart_handle);

	/* enable interrupt */
	HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);

}

uint8_t buffer = 0;
uint8_t *string;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_uart();

	string = (uint8_t*) calloc(1, sizeof(uint8_t));

	while (1) {
		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}

}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
	if (huart->Instance == USART1) {
		int length = strlen(string);
		string = (uint8_t*) realloc(string, sizeof(uint8_t) * length + 2);
		string[length] = buffer;
		string[length + 1] = '\0';

		if (buffer == '\n')
			printf("%s", string);

		buffer = 0;
		/* you have to restart the reception again: */
		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}
}

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
