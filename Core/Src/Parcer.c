#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f1xx_hal_uart.h"

#include "LedDriver.h"
#include "LedProc.h"

uint8_t test (void)
{
	char end = 0;
	uint8_t arr[128] = {};
	char value[128]= {};

	for (uint8_t counter = 0; counter < 100; counter++)
	{
		HAL_UART_Receive_IT(&huart1, value, sizeof(value));
		arr[counter] = value[counter];

		if (value[counter] == end)
		{
			arr[counter] = value[counter];
			counter = 0;
			HAL_UART_RxCpltCallback(&huart1);
		}
	}
}


