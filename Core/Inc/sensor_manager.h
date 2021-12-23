/*
 * sensor_manager.h
 *
 *  Created on: 08 dec. 2021
 *      Author: Alexandre Foucher
 */

#ifndef INC_SENSOR_MANAGER_H_
#define INC_SENSOR_MANAGER_H_

#include <i2c.h>
#include <serial.h>
#include <APDS9960.h>

class sensor_manager{
public:
	static void init(I2C_HandleTypeDef *hi2c);
	static void triggerInterrupt();
	static void update();

private:
	static APDS9960 *_apds;
	static bool _isInterrupt;
};

#endif /* INC_SENSOR_MANAGER_H_ */
