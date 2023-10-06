#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f1xx_hal_uart.h"

#include "LedDriver.h"
#include "LedProc.h"

uint8_t test (void)
{
	uint8_t data[] = "Hello World \n";
	HAL_UART_Transmit(&huart1, data, sizeof (data), 10);
}
