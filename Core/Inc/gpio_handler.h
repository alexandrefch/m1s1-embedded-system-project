/*
 * @file    gpio_handler.h
 *
 * @brief   GPIO handler for a specific pin
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#ifndef INC_GPIO_HANDLER_H_
#define INC_GPIO_HANDLER_H_

#include "stm32f4xx_hal.h"

#define LOW  0
#define HIGH 1

class GPIO_Handler {
public:
	GPIO_Handler(GPIO_TypeDef *GPIOx, uint16_t pin);
	~GPIO_Handler();
	void set(uint8_t mode);

private:
	GPIO_TypeDef *_GPIOx;
	uint16_t      _pin;
};

#endif /* INC_GPIO_HANDLER_H_ */
