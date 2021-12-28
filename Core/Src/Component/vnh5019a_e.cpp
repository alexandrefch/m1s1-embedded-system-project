/*
 * @file    vnh5019a_e.cpp
 *
 * @brief   Library for the Pololu VNH5019A_E motor driver
 * @see     https://www.pololu.com/file/0J504/vnh5019a-e.pdf
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#include <Component/vnh5019a_e.h>

/**
 * @brief Constructor - Instantiates vnh5019a_e object
 */
vnh5019a_e::vnh5019a_e(GPIO_Handler *ina, GPIO_Handler *inb,
		TIM_TypeDef *pwm) {
	this->_ina = ina;
	this->_inb = inb;
	this->_pwm = pwm;
	this->_period = 0;
	stop();
}

/**
 * @brief Destructor
 */
vnh5019a_e::~vnh5019a_e() {
	stop();
}

/*******************************************************************************
 * Public methods for controlling the VNH5019A_E
 ******************************************************************************/

/**
 * @brief Stop rotation
 */
void vnh5019a_e::stop() {
	_ina->set(LOW);
	_inb->set(LOW);
}

/**
 * @brief Set rotation direction to the left
 */
void vnh5019a_e::turnLeft() {
	_ina->set(LOW);
	_inb->set(HIGH);
}

/**
 * @brief Set rotation direction to the right
 */
void vnh5019a_e::turnRight() {
	_inb->set(LOW);
	_ina->set(HIGH);
}

/**
 * @brief Change the pwm period
 */
void vnh5019a_e::updateSpeed(int32_t value) {
	if(_period + value <= 0)
		_period = 0;
	else if(value + _period >= 65535)
		_period = 65535;
	else
		_period += value;
	serial::print(_period);
	serial::println("");
	_pwm->CCR1 = _period;
}
