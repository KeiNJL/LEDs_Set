#include "main.h"
#include "gpio.h"
#include "LedDriver.h"




#define Led_OFF 0
#define Led_ON 1
#define Led_Blink 2
#define Led_Fast_Blink 3

uint8_t LEDs_arr[5] = {0, 1, 0, 1, 0};
uint8_t value = 0b00000;

void Blink(void)
{
	uint32_t current_time = HAL_GetTick();
	uint32_t previous_time = 0;
	uint8_t value = 0b0;

		if ((current_time - previous_time) > 1000)
		{
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			previous_time = current_time;
			if (value&0b00001 == 0b00000)
			{
				value = value | 1;
				value << 1;
			}
			else
			{
				value = value | 0;
				value << 1;
			}
		}
}
void FastBlink(void)
{
	uint32_t current_time = HAL_GetTick();
	uint32_t previous_time = 0;
	uint8_t value = 0b0;

		if ((current_time - previous_time) > 500)
		{
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			previous_time = current_time;
			if (value&0b00001 == 0b00000)
			{
				value = value | 1;
				value << 1;
			}
			else
			{
				value = value | 0;
				value << 1;
			}
		}
}


void ledProc (void)
{
	if (LEDs_arr[0] == 0)
	{
		value << 1;
	}
	else if (LEDs_arr[0] == 1)
	{
		value = value | 1;
		value << 1;
	}
	else if (LEDs_arr[0] == 2)
	{
		Blink();
	}
	else if (LEDs_arr[0] == 3)
	{
		FastBlink();
	}
}



