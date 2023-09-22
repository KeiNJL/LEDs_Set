#include "main.h"
#include "gpio.h"

void LedSet(uint8_t value) {
	uint8_t led1 = 0, led2 = 0, led3 = 0, led4 = 0, led5 = 0;

	led1 = (value & 0b1);
	led2 = (value & 0b10) >> 1;
	led3 = (value & 0b100) >> 2;
	led4 = (value & 0b1000) >> 3;
	led5 = (value & 0b10000) >> 4;

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

void LedTest(void){
	for (uint8_t i = 0; i<0b100000; i++)
	{
		LedSet(i);
		HAL_Delay(500);
	}
}
void LedTest1(void){
	//LedSet(0b00000);
	//HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);

}

