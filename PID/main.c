#include "poller.h"
#include "tc72.h"
#include "uart.h"
#include "spi.h"
#include "PID.h"
#include "timer.h"
#include <avr/io.h>

#define F_CPU 8000000UL

// Main Function
int main(void) {
	SPI_MasterInit();
	TC72_InitSensor();
	USART_Init();
	PWM_Init();
	
	
	poller_Init();
	Poller__StartPolling();
	poller_SetPollTime(500);


	DDRB |= (1 << PB0);  
	PORTB |= (1 << PB0); 
		
	while (1) {
	}

	return 0;
}
