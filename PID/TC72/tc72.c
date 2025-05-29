#include "tc72.h"
#include "spi.h"
#include "avr/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void TC72_InitSensor(void) {
	PORTB |= (1U << 4U);
	SPI_MasterTransmit(0x80);
	SPI_MasterTransmit(0x04);
	PORTB &= ~(1U << 4U);
	_delay_ms(150);
}

DeviceDataType TC72_ReadTemperature(void) {
	uint8 msb;
  uint8 lsb;

	PORTB |= (1U << 4U);
	SPI_MasterTransmit(0x02);
	SPI_MasterTransmit(0x00);
	PORTB &= ~(1U << 4U);
	_delay_ms(1);
	msb = SPI_MasterReceive();

	PORTB |= (1U << 4U);
	SPI_MasterTransmit(0x01);
	SPI_MasterTransmit(0x00);
	PORTB &= ~(1U << 4U);
	_delay_ms(1);
	lsb = SPI_MasterReceive();

	return ((msb << 2U) | (lsb >> 6U));
}

DeviceStateType TC72_CheckSensorState(void) {
	DeviceDataType temperature = TC72_ReadTemperature(); 
	uint8 status = true;
  
	if (temperature == 0xFFF) {
		status = false; // Sensor failure or invalid reading
	}

	return status; // Sensor is working correctly
}