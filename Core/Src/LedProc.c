#include "main.h"
#include "gpio.h"
#include "LedDriver.h"

#define Led_OFF 0
#define Led_ON 1
//#define Led_Blink 2
//#define Led_Fast_Blink 3



uint8_t LEDs_arr[5] = {0, 0, 0, 0, 0};


void setLedMode(uint8_t led, uint8_t mode) {
    if (led >= 1 && led <= 5) {
    	LEDs_arr[led - 1] = mode;

        GPIO_TypeDef* GpioPort;
        uint16_t GpioPin;

        switch (led) {
            case 1:
                GpioPort = GPIOA;
                GpioPin = GPIO_PIN_1;
                break;
            case 2:
                GpioPort = GPIOA;
                GpioPin = GPIO_PIN_2;
                break;
            case 3:
                GpioPort = GPIOA;
                GpioPin = GPIO_PIN_3;
                break;
            case 4:
                GpioPort = GPIOA;
                GpioPin = GPIO_PIN_4;
                break;
            case 5:
                GpioPort = GPIOA;
                GpioPin = GPIO_PIN_5;
                break;

                return;
        }

        if (mode == 1) {
            HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_RESET);
        }
    }
}
