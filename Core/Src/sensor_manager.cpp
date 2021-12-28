/*
 * sensor_manager.cpp
 *
 *  Created on: 8 déc. 2021
 *      Author: Alexandre
 */

#include <sensor_manager.h>

apds9960 *sensor_manager::_apds = nullptr;

bool sensor_manager::_isInterrupt = false;

void sensor_manager::init(I2C_HandleTypeDef *hi2c, vnh5019a_e *motorDriver) {
	_apds = new apds9960(hi2c, motorDriver);

	// Initialize APDS-9960 (configure I2C and initial values)
	if (_apds->init()) {
		serial::println("APDS-9960 initialization complete");
	} else {
		serial::println("Something went wrong during APDS-9960 init!");
	}

	// Start running the APDS-9960 gesture sensor engine
	if (_apds->enableGestureSensor(true)) {
		serial::println("Gesture sensor is now running");
	} else {
		serial::println("Something went wrong during gesture sensor init!");
	}
}

void sensor_manager::triggerInterrupt() {
	_isInterrupt = true;
}

void sensor_manager::update() {
	if (_isInterrupt) {
		if (_apds->isGestureAvailable()) {
			switch (_apds->readProximityGesture()) {
			case DIR_LEFT:
				serial::println("LEFT");
				break;
			case DIR_RIGHT:
				serial::println("RIGHT");
				break;
			default:
				serial::println("NONE");
			}
		}
		_isInterrupt = false;
	}
}
