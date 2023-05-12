#ifndef UART_H_
#define UART_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void UART0_Init(int baudRate);

unsigned char ReadUart0(void);

void WriteUart0(unsigned char c);

void UART5_Init(unsigned long baudRate);

void UART5_WriteChar(unsigned char ch);

unsigned char UART5_ReadChar(void);

void UART5_ReadString(char *str, char stopCh);

#endif // !UART_H
