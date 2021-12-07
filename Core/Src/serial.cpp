/*
 * serial.cpp
 *
 *  Created on: Nov 17, 2021
 *      Author: Alexandre FOUCHER
 */

#include <serial.h>

UART_HandleTypeDef *serial::_uart = NULL;

void serial::setUart(UART_HandleTypeDef *uart){
	serial::_uart = uart;
}

void serial::println(const char *message){
	serial::print(message);
	serial::print("\r\n");
}

void serial::print(const char *message){
	HAL_UART_Transmit(
		serial::_uart,
		(uint8_t *)message,
		strlen(message),
		HAL_MAX_DELAY
		);
}

void serial::printHex(const uint8_t val){
	char buffer[4];
	sprintf(buffer, "%x", val);
	serial::print(buffer);
}

void serial::print(const uint8_t val){
	char buffer[4];
	sprintf(buffer, "%d", val);
	serial::print(buffer);
}

void serial::print(const uint16_t val){
	char buffer[6];
	sprintf(buffer, "%d", val);
	serial::print(buffer);
}
