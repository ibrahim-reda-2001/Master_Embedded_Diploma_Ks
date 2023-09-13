/*
 * Alarm_Actuator.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ibrahim
 */
//Includes
#include "Alarm_Actuator.h"
#include "driver.h"

//Module Variables
extern void (*Alarm_Actuator_state)();

//Functions

void Alarm_Actuator_init(){

	//Set first state
	Alarm_Actuator_state = STATE(Alarm_Actuator_off);//this is default
}

/* Alarm_Monitor ---> Alarm_Actuator_Driver */
void Start_Alarm_Actuator()//this is connection
{

	//Set equivalent state
	Alarm_Actuator_state = STATE(Alarm_Actuator_on);
}

void Stop_Alarm_Actuator()//this is connection
{
	//Set equivalent state
	Alarm_Actuator_state = STATE(Alarm_Actuator_off);
}


STATE_DEFINE(Alarm_Actuator_off){
	Start_Alarm(OFF);//this from driver take 0 to off
}

STATE_DEFINE(Alarm_Actuator_on){
	Start_Alarm(ON); //this from driver take 1 to on
}
