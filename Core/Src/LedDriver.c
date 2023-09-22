#include "main.h"
#include "gpio.h"

void LedSet(uint8_t value) {
	uint8_t led1 = 0, led2 = 0, led3 = 0, led4 = 0, led5 = 0;
	led1 = (value & 10000) >> 4;
	led2 = (value & 1000) >> 3;
	led3 = (value & 100) >> 2;
	led4 = (value & 10) >> 1;
	led5 = value & 1;


	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,
			led1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,
			led2 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin,
			led3 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,
			led4 ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin,
			led5 ? GPIO_PIN_SET : GPIO_PIN_RESET);

}

void LedTest1(void){
	for (uint8_t i = 0; i<0b11111; i++)
	{
		LedSet(i);
		HAL_Delay(500);
	}
}
void LedTest(void){
	LedSet(0b11111);
	/*HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);*/

}

