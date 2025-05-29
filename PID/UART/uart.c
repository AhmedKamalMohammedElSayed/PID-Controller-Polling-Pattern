#include "uart.h"
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 8000000UL

void USART_Init(void) {
	uint8 ubrr = ((F_CPU / 16U) / 9600U) - 1U;
	UBRRH = (unsigned char)(ubrr >> 8U);
	UBRRL = (unsigned char)ubrr;
	UCSRB = (1U << TXEN);
	UCSRC = (1U << UCSZ1) | (1U << UCSZ0);
}

void USART_TransmitChar(char data) {
	while (!(UCSRA & (1 << UDRE))){};
	UDR = data;
}

void USART_TransmitString(const char *str) {
    const char *ptr = str;  
    while (*ptr != '\0') {
        USART_TransmitChar(*ptr++);
    }
}

uint8 DisplayTemperature(int temperature) {
	char buffer[16];
  uint8 status = 1;
  int result = snprintf(buffer, sizeof(buffer), "Temperature: %d.%02d C\n", temperature / 4, (temperature % 4) * 25);
  if (result < 0) {
    status = 0;
  } 
  else{}
	USART_TransmitString(buffer);
  return status;
}
