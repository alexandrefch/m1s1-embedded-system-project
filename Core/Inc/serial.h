/*
 * Uart.h
 *
 *  Created on: 15 nov. 2021
 *      Author: Alexandre Foucher
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#include <stm32f4xx_hal.h>
#include <string.h>
#include <stdio.h>

class serial{
public:
	static void setUart (UART_HandleTypeDef *uart);
	static void println (const char *message);
	static void print   (const char *message);
	static void printHex(uint8_t val);
	static void printInt(uint8_t val);

private:
	static UART_HandleTypeDef *_uart;
};

#endif /* INC_SERIAL_H_ */
