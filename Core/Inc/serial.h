/*
 * @file    uart.h
 *
 * @brief   Library for the Pololu VNH5019A_E motor driver
 * @see     https://www.pololu.com/file/0J504/vnh5019a-e.pdf
 *
 * @author  Alexandre Foucher (Student of University of Bretagne Sud (Lorient, FRANCE))
 * @date    December 2021
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
	static void printHex(const uint8_t val);
	static void print   (const uint8_t val);
	static void print   (const uint16_t val);
	static void print   (const int32_t val);

private:
	static UART_HandleTypeDef *_uart;
};

#endif /* INC_SERIAL_H_ */
