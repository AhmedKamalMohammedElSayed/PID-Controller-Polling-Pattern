#include "PID.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

static float32 previous_error = 0.0;
static float32 integral = 0.0;


float32 PID_Controller(float32 setpoint, float32 current_temp) {
	
	float32 kp = 0.1;
	float32 ki = 0.01;
	float32 kd = 0.0;
	
	float error =  ((setpoint - current_temp));
	
	float derivative = error - previous_error;
	integral += ((error+ previous_error)/2);
	previous_error = error;

	float output = (kp * error) + (ki * integral) + (kd * derivative);

	if (output > 0.73) {
		output = 0.73;
	} 
	else if (output < 0.0) {
		output = 0.0;
	}
  else{}
	
	return output;
}
