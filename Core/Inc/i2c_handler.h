/*
 * @file    i2c_handler.h
 *
 * @brief   I2C link handler for a specific device
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#ifndef INC_I2C_HANDLER_H_
#define INC_I2C_HANDLER_H_

#include <stm32f4xx_hal.h>

class I2C_Handler {
public:
	I2C_Handler(I2C_HandleTypeDef *i2cHandler, uint8_t deviceAddr);
	~I2C_Handler();
	bool writeByte(uint8_t reg);
	bool writeDataByte(uint8_t reg, uint8_t val);
	bool writeDataBlock(uint8_t reg, uint8_t *val, uint8_t len);
	bool readDataByte(uint8_t reg, uint8_t &val);
	uint8_t readDataBlock(uint8_t reg, uint8_t *val, uint8_t len);

private:
	I2C_HandleTypeDef *_i2cHandler;
	uint8_t _deviceAddr;
};

#endif /* INC_I2C_HANDLER_H_ */
