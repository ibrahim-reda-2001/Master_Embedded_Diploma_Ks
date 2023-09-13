/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ibrahim
 */
#include "Main_ALG.h"

//Module Variables
int Main_pressureVal = 0;
int Main_pressure_threshold = Pthreshold;

extern void (*Main_Algorithm_state)();


//Functions



/*PressureSensor_Driver ---> Main_ALG*/
void SetPressureValue(int pressureVal){

	Main_pressureVal = pressureVal;
	Main_Algorithm_state = STATE(High_Pressure_Check);

}

STATE_DEFINE(High_Pressure_Check){

	//Receive pressure reading signal (PressureSensor_Driver ---> Main_ALG)

	//State ID
	Main_Algorithm_state_id = High_Pressure_Check;


	//Main Algorithm
	if(Main_pressureVal > Main_pressure_threshold ){

		//Main_ALG ---> Alarm_Monitor
		HighPressureDetected();

	}

	//Update state
	Main_Algorithm_state = STATE(High_Pressure_Check);

}
