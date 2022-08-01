/*
 * uart.h
 *
 *  Created on: 05-09-2011
 *      Author: admin
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "util/delay.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define USART_BAUD 115200ul
#define USART_UBBR_VALUE ((F_CPU/(USART_BAUD<<4))-1)

#define TX_NEWLINE {uart_send(0x0d); uart_send(0x0a);}

void uart_init(void);
void uart_send(uint8_t u8Data);
uint8_t uart_receive();
void usart_putchar(uint8_t u8Data);
void uart_send_string_from_FLASH(char* string);
void uart_send_string(unsigned char* string);
int usart_putchar_printf(char var, FILE *stream);

#endif /* UART_H_ */
