/*
 * @file    vnh5019a_e.h
 *
 * @brief   Library for the Pololu VNH5019A_E motor driver
 * @see     https://www.pololu.com/file/0J504/vnh5019a-e.pdf
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#ifndef INC_VNH5019A_E_H_
#define INC_VNH5019A_E_H_

#include "stm32f4xx_hal.h"
#include <gpio_handler.h>
#include <serial.h>

/* VNH5019A_E Class */
class vnh5019a_e {
public:

	/* Initialization methods */
	vnh5019a_e(GPIO_Handler *ina, GPIO_Handler *inb, TIM_TypeDef *pwm);
	~vnh5019a_e();

	void stop();

	/* Rotation control */
	void turnLeft();
	void turnRight();

	/* Speed control */
	void updateSpeed(int32_t value);

private:

	/* Members */
	GPIO_Handler *_ina;
	GPIO_Handler *_inb;
	TIM_TypeDef  *_pwm;
	int32_t       _period;
};

#endif /* INC_VNH5019A_E_H_ */
