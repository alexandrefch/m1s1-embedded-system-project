/*
 * @file    gpio_handler.cpp
 *
 * @brief   GPIO handler for a specific pin
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#include <gpio_handler.h>

/**
 * @brief Constructor - Instantiates GPIO_Handler object
 */
GPIO_Handler::GPIO_Handler(GPIO_TypeDef *GPIOx, uint16_t pin) {
	this->_GPIOx = GPIOx;
	this->_pin = pin;
}

/**
 * @brief Destructor
 */
GPIO_Handler::~GPIO_Handler() {

}

/*******************************************************************************
 * Public methods for controlling the VNH5019A_E
 ******************************************************************************/

/**
 * @brief Set pin mode (LOW or HIGH)
 */
void GPIO_Handler::set(uint8_t mode) {
	if (mode == HIGH)
		this->_GPIOx->ODR |= this->_pin;
	else
		this->_GPIOx->ODR &= ~this->_pin;
}
