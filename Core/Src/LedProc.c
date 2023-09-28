#include "main.h"
#include "gpio.h"
#include "LedDriver.h"




#define Led_OFF 0
#define Led_ON 1
#define Led_Blink 2
#define Led_Fast_Blink 3


uint8_t LEDs_arr[5] = {0, 1, 0, 1, 0};
uint8_t value = 0b00000;

void ledProc (void)
{
	if (LEDs_arr[0] == 0)
	{
		value << 1;
	}
	else if (LEDs_arr[0] == 1)
	{
		value|(value+1);
		value << 1;
	}
	else if (LEDs_arr[0] == 2)
	{
		value|(value+1);
		value << 1;
		HAL_GetTick(500);
	}
	else if (LEDs_arr[0] == 3)
	{
		value|(value+1);
		value << 1;
		HAL_GetTick(100);
	}


	if (LEDs_arr[1] == 0)
		{
				value << 1;
		}
		else if (LEDs_arr[1] == 1)
		{
			value|(value+1);
					value << 1;
		}
		else if (LEDs_arr[1] == 2)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(500);
		}
		else if (LEDs_arr[1] == 3)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(100);
		}


	if (LEDs_arr[2] == 0)
		{
				value << 1;
		}
		else if (LEDs_arr[2] == 1)
		{
			value|(value+1);
					value << 1;
		}
		else if (LEDs_arr[2] == 2)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(500);
		}
		else if (LEDs_arr[2] == 3)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(100);
		}



	if (LEDs_arr[3] == 0)
		{
				value << 1;
		}
		else if (LEDs_arr[3] == 1)
		{
			value|(value+1);
					value << 1;
		}
		else if (LEDs_arr[3] == 2)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(500);
		}
		else if (LEDs_arr[3] == 3)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(100);
		}


	if (LEDs_arr[4] == 0)
		{
				value << 1;
		}
		else if (LEDs_arr[4] == 1)
		{
			value|(value+1);
					value << 1;
		}
		else if (LEDs_arr[4] == 2)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(500);
		}
		else if (LEDs_arr[4] == 3)
		{
			value|(value+1);
					value << 1;
			HAL_GetTick(100);
		}
}


