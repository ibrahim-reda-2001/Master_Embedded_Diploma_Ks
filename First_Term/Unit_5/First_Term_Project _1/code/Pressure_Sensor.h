/*
 * Pressure_Sensor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
//Defines
#define Psensor_pressure_pull_time 6000

//Includes
#include "state.h"

//State IDs
enum{
	Pressure_sensor_reading,
	Pressure_sensor_waiting
}pressureSensor_State;


//Prototypes
void PressureSensor_init();
STATE_DEFINE(Pressure_sensor_reading);
STATE_DEFINE(Pressure_sensor_waiting);


//State pointer
void (*PSensor_state)();


#endif /* PRESSURE_SENSOR_H_ */
