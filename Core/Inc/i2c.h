/*
 * I2C.h
 *
 *  Created on: 15 nov. 2021
 *      Author: Alexandre Foucher
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include <stm32f4xx_hal.h>

class i2c{
public:
	i2c(I2C_HandleTypeDef *i2cHandler, uint8_t deviceAddr);
	~i2c();
	bool writeByte     (uint8_t reg);
	bool writeDataByte (uint8_t reg, uint8_t val);
	bool writeDataBlock(uint8_t reg, uint8_t *val, uint8_t len);
	bool readDataByte  (uint8_t reg, uint8_t &val);
	bool readDataBlock (uint8_t reg, uint8_t *val, uint8_t len);

private:
	I2C_HandleTypeDef *_i2cHandler;
	uint8_t            _deviceAddr;
};

#endif /* INC_I2C_H_ */
