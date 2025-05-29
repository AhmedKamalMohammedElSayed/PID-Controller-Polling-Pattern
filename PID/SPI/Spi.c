#include "spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Std_Types.h"

void SPI_MasterInit(void) {
	DDRB = (1U << 7U) | (1U << 5U) | (1U << 4U);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0) | (1 << CPHA);
}

void SPI_MasterTransmit(char data) {
	SPDR = data;
	while (!(SPSR & (1U << SPIF))){};
}

char SPI_MasterReceive(void) {
	while (!(SPSR & (1 << SPIF))){};
	return SPDR;
}
