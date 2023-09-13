/*

 * Alarm_monitor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */
#include "Alarm_monitor.h"
#include"driver.h"

//Module Variables
extern void (*Alarm_Monitor_state)();


//Functions

//Main_Algorithm ---> Alarm_Monitor
void HighPressureDetected(){
	Alarm_Monitor_state = STATE(Alarm_Monitor_AlarmOn);
}


STATE_DEFINE(Alarm_Monitor_AlarmOff){
	Alarm_Monitor_state_id = Alarm_Monitor_AlarmOff;
	//Do nothing until high pressure is detected
	}


STATE_DEFINE(Alarm_Monitor_AlarmOn){

	//State ID
	Alarm_Monitor_state_id = Alarm_Monitor_AlarmOn;

	//Alarm_Monitor ---> Alarm_Actuator_Driver
	Start_Alarm_Actuator();


	//set next state
	Alarm_Monitor_state = STATE(Alarm_Monitor_waiting);

}

STATE_DEFINE(Alarm_Monitor_waiting){

	Alarm_Monitor_state_id = Alarm_Monitor_waiting;

	//wait for alarm_duration
	Delay(alarm_duration);

	//stop alarm
	Stop_Alarm_Actuator();

	//set next state
	Alarm_Monitor_state = STATE(Alarm_Monitor_AlarmOff);


}
