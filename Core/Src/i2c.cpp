/*
 * I2C.cpp
 *
 *  Created on: Nov 17, 2021
 *      Author: Alexandre FOUCHER
 */

#include <i2c.h>

i2c::i2c(I2C_HandleTypeDef *i2cHandler, uint8_t deviceAddr){
	this->_i2cHandler = i2cHandler;
	this->_deviceAddr = deviceAddr;
}

i2c::~i2c(){}

bool i2c::writeByte(uint8_t reg){
	return HAL_I2C_Master_Transmit(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			&reg,
			1,
			HAL_MAX_DELAY
			) == HAL_OK;
}

bool i2c::writeDataByte(uint8_t reg, uint8_t val){
	uint8_t data[2] = {reg, val};

	return HAL_I2C_Master_Transmit(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			data,
			2,
			HAL_MAX_DELAY
			) == HAL_OK;
}

bool i2c::writeDataBlock(uint8_t reg, uint8_t *val, uint8_t len){
	uint8_t data[len+1];

	data[0] = reg;
	for(int i=1; i<len; i++)
		data[i] = val[i-1];

	return HAL_I2C_Master_Transmit(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			data,
			len+1,
			HAL_MAX_DELAY
			) == HAL_OK;
}

bool i2c::readDataByte(uint8_t reg, uint8_t &val){
	return readDataBlock(reg, &val, 1);
}

bool i2c::readDataBlock(uint8_t reg, uint8_t *val, uint8_t len){
	this->writeByte(reg);

	return HAL_I2C_Master_Receive(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			val,
			len,
			HAL_MAX_DELAY
			) == HAL_OK;
}
