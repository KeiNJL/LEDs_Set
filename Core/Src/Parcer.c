#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f1xx_hal_uart.h"

#include "LedDriver.h"
#include "LedProc.h"

uint8_t test (void)
{
	char r = 0;
	uint8_t data[] = {"Hello World! "};
	HAL_UART_Transmit(&huart1, data, sizeof(data), 100);

	for (uint8_t i = 0; i<sizeof(data); i++)
	{
		if (data[i] == r)
		{
			HAL_UART_Receive_IT(&huart1, &data, sizeof(data));
		}
	}
}


//ловить нулевой бит + прерывания*

