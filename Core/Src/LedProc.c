#include "main.h"
#include "gpio.h"
#include "LedDriver.h"




#define Led_OFF 0
#define Led_ON 1
#define Led_Blink 2
#define Led_Fast_Blink 3

uint8_t LEDs_arr[5] = {0, 0, 0, 0, 0};
uint8_t leds = 0b00000;
uint8_t LedMask;
static uint32_t current_time = 0;
static uint32_t previous_time2 = 0;
static uint32_t previous_time3 = 0;
static uint8_t state2 = 0;
static uint8_t state3 = 0;

uint8_t GetMode(uint8_t mode)
{
	current_time = HAL_GetTick();
	switch (mode)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		if ((current_time - previous_time2) > 1000)
		{
			previous_time2 = current_time;
			state2 = !state2;

		}
		return state2;

	case 3:
		if ((current_time - previous_time3) > 500)
		{
			previous_time3 = current_time;
			state3 = !state3;

		}
		return state3;
	}
	return 0;
}


void ledProc (void)
{
	uint8_t LedMask = 0;
	for (uint8_t i = 0; i < 5; i++)
	{
		LedMask = GetMode(LEDs_arr[i]);
		leds |= LedMask << i;
	}
	LedSet(leds);
}
//


