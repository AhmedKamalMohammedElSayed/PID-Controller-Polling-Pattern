#ifndef UART_H
#define UART_H
#include "Std_Types.h"

void USART_Init(void);
void USART_TransmitChar(char data);
void USART_TransmitString(const char *str);
uint8 DisplayTemperature(int temperature);

#endif
