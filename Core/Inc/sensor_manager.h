/*
 * sensor_manager.h
 *
 *  Created on: 08 dec. 2021
 *      Author: Alexandre Foucher
 */

#ifndef INC_SENSOR_MANAGER_H_
#define INC_SENSOR_MANAGER_H_

#include <Component/apds9960.h>
#include <Component/vnh5019a_e.h>
#include <i2c_handler.h>
#include <serial.h>

class sensor_manager{
public:
	static void init(I2C_HandleTypeDef *hi2c, vnh5019a_e *motorDriver);
	static void triggerInterrupt();
	static void update();

private:
	static apds9960 *_apds;
	static bool _isInterrupt;
};

#endif /* INC_SENSOR_MANAGER_H_ */
