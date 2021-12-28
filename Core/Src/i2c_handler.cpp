/*
 * @file    i2c_handler.cpp
 *
 * @brief   I2C link handler for a specific device
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud, FRANCE)
 * @date    December 2021
 */

#include <i2c_handler.h>

/**
 * @brief Constructor - Instantiates I2C_Handler object
 */
I2C_Handler::I2C_Handler(I2C_HandleTypeDef *i2cHandler, uint8_t deviceAddr){
	this->_i2cHandler = i2cHandler;
	this->_deviceAddr = deviceAddr;
}

/**
 * @brief Destructor
 */
I2C_Handler::~I2C_Handler(){

}

/*******************************************************************************
 * Public methods for controlling the VNH5019A_E
 ******************************************************************************/

/**
 * @brief Write only one byte (useful to trigger a register)
 * @see I2C_Handler::writeDataBlock
 * @param reg (uint8_t) | register ID
 * @return true if nothing went wrong, false otherwise
 */
bool I2C_Handler::writeByte(uint8_t reg){
	return writeDataBlock(reg, nullptr, 0);
}

/**
 * @brief Write only one byte of data to specific register
 * @see I2C_Handler::writeDataBlock
 * @param reg (uint8_t) | register ID
 * @parem val (uint8_t) | value
 * @return true if nothing went wrong, false otherwise
 */
bool I2C_Handler::writeDataByte(uint8_t reg, uint8_t val){
	return writeDataBlock(reg, &val, 1);
}

/**
 * @brief Write bytes array of data to specific register
 * @param reg ( uint8_t) | register ID
 * @parem val (*uint8_t) | bytes array
 * @parem len ( uint8_t) | length of the 'val' bytes array
 * @return true if nothing went wrong, false otherwise
 */
bool I2C_Handler::writeDataBlock(uint8_t reg, uint8_t *val, uint8_t len){
	uint8_t data[len+1];

	data[0] = reg;
	for(int i=0; i<len; i++)
		data[i+1] = val[i];

	return HAL_I2C_Master_Transmit(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			data,
			len+1,
			HAL_MAX_DELAY
			) == HAL_OK;
}

/**
 * @brief Read only one byte of specific register
 * @see I2C_Handler::readDataBlock
 * @param reg ( uint8_t) | register ID
 * @param val (&uint8_t) | pointer to the value
 * @return true if nothing went wrong, false otherwise
 */
bool I2C_Handler::readDataByte(uint8_t reg, uint8_t &val){
	return readDataBlock(reg, &val, 1) != -1;
}

/**
 * @brief Write only one byte on IC2 (useful to trigger a register)
 * @param reg ( uint8_t) | register ID
 * @param val (*uint8_t) | pointer to bytes array
 * @param len ( uint8_t) | length of readed data
 * @return -1 if something went wrong, length (len) otherwise
 */
uint8_t I2C_Handler::readDataBlock(uint8_t reg, uint8_t *val, uint8_t len){
	this->writeByte(reg);

	uint8_t res = HAL_I2C_Master_Receive(
			this->_i2cHandler,
			this->_deviceAddr<<1,
			val,
			len,
			HAL_MAX_DELAY
			);

	return (res==HAL_OK)?len:-1;
}
