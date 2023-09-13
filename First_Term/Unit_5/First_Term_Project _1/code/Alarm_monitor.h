/*
 * Alarm_monitor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

//Defines
#define alarm_duration 30000

//Includes
#include "state.h"

//States IDs
enum{
	Alarm_Monitor_AlarmOn,
	Alarm_Monitor_AlarmOff,
	Alarm_Monitor_waiting
}Alarm_Monitor_state_id;


//Prototypes
STATE_DEFINE(Alarm_Monitor_AlarmOn);
STATE_DEFINE(Alarm_Monitor_AlarmOff);
STATE_DEFINE(Alarm_Monitor_waiting);

//State pointer
void (*Alarm_Monitor_state)();

#endif /* ALARM_MONITOR_H_ */
