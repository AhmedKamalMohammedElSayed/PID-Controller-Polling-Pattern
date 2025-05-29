#include "poller.h"
#include "tc72.h"
#include "PID.h"
#include "uart.h"
#include "timer.h"
#include "timer_cfg.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint16 static pollCounter =0;
uint16 static pollTimeCounter=0;



static void poll(void) {
updatePollCounter();
if ((pollCounter == pollTimeCounter)) {
	pollCounter=0;
	DeviceStateType tc72_state = TC72_CheckSensorState();

	if (tc72_state)
	{
			DeviceDataType raw_temperature = TC72_ReadTemperature();
			DeviceDataType current_temp = raw_temperature / 4;
			DisplayTemperature(raw_temperature);
			float32 dutyCycle = PID_Controller(30.0, current_temp);
			SetPWMDutyCycle(dutyCycle);
	}
}
}

static void updatePollCounter(void) {
	pollCounter += 1; 
}

void poller_Init(void) {
Timer_vidInitTimer1();
Timer_vidSetCallBackTimer1(poll);
}

void Poller__StartPolling(void) {
Timer_vidStartTimer1();
}

void Poller__StopPolling(void) {
Timer_vidStopTimer1();
}


void poller_SetPollTime(uint32 time) {

pollTimeCounter = time / time_ms;

}