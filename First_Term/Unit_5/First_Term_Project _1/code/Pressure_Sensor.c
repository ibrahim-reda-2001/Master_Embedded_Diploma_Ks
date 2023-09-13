#include "Pressure_Sensor.h"
#include "driver.h"




//Module Variables
int Psensor_pressureVal = 0;

extern void (*PSensor_state)();


//Functions

void PressureSensor_init(){

	//Set first state
	PSensor_state = STATE(Pressure_sensor_reading);

}

STATE_DEFINE(Pressure_sensor_reading){

	//Read pressure value from pressure sensor
	Psensor_pressureVal = getPressureVal();

	//Send signal (PressureSensor_Driver ---> Main_Algorithm)
	SetPressureValue(Psensor_pressureVal);

	//Update state
	PSensor_state = STATE(Pressure_sensor_waiting);

}

STATE_DEFINE(Pressure_sensor_waiting){

	//Delay between readings
	Delay(Psensor_pressure_pull_time);

	//Set first state
	PSensor_state = STATE(Pressure_sensor_reading);

}
