#ifndef TC72_H
#define TC72_H
#include "Std_Types.h"
typedef uint16 DeviceDataType ;
typedef enum{false = 0, true = 1} DeviceStateType ;

void TC72_InitSensor(void);
DeviceDataType TC72_ReadTemperature(void);
DeviceStateType TC72_CheckSensorState(void);
#endif
