#ifndef UART_H
#define UART_H

#include <ch32v00x.h>

void USART1_Init(void);
void USART1_SendChar(char c);
void USART1_SendString(const char *str);
void USART1_SendNumber(uint32_t num);

#endif
