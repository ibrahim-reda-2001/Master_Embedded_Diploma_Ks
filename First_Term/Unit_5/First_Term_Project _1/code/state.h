
#ifndef STATE_H_
#define STATE_H_
#include<stdint.h>


//Defines
#define STATE_DEFINE(_state_func_) void stateFunction_##_state_func_()
#define STATE(_state_func_) stateFunction_##_state_func_


//connection in UML


//PressureSensor_Driver ---> Main_ALG
void SetPressureValue(int pressureVal);

//Main_ALG ---> Alarm_Monitor
void HighPressureDetected();

//Alarm_Monitor ---> Alarm_Actuator_Driver
void Start_Alarm_Actuator();
void Stop_Alarm_Actuator();

#endif /* STATE_H_ */
