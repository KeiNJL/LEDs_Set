#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f1xx_hal_uart.h"

#include "LedDriver.h"
#include "LedProc.h"

char end = '\0';
char string[10];
uint8_t arr[10];
char symbol[10];
uint8_t counter = 0;

uint8_t test (UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart1, &symbol, 10);
	if (huart == &huart1)
	{
		if (symbol == '\r')
		{
			Proc(string);
	        counter = 0;
	        HAL_UART_RxCpltCallback(&huart1);
	    }
		else
		{
	        string[counter] = symbol[counter];
	        counter++;
	    }
	}
}

void Proc(char *string)
{
    for (uint8_t i = 0; string[i] != '\0'; i++)
    {
    	arr[i] = string[i];
    }
}





//	char end = 0;
//	uint8_t arr[128] = {};
//	char value[128]= {};
//
//	for (uint8_t counter = 0; counter < 100; counter++)
//	{
//		HAL_UART_Receive_IT(&huart1, value, sizeof(value));
//		arr[counter] = value[counter];
//
//		if (value[counter] == end)
//		{
//			arr[counter] = value[counter];
//			counter = 0;
//			HAL_UART_RxCpltCallback(&huart1);
//		}
//	}

