#include <stdint.h>

#include "Pressure_Sensor.h"
#include "Main_ALG.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"

#include "driver.h"

void setup(){

//All initializations

	GPIO_INITIALIZATION();

	PressureSensor_init();
	Alarm_Actuator_init();

	//Initialize states
	Alarm_Monitor_state = STATE(Alarm_Monitor_AlarmOff);
	Main_Algorithm_state = STATE(High_Pressure_Check);

}


int main (){

	 setup();

	 //SUPER LOOP
	while (1)
	{

		PSensor_state();
		Main_Algorithm_state();

		//for algorithm confirmation
		Alarm_Monitor_state();
		Alarm_Actuator_state();
		Alarm_Monitor_state();
		Alarm_Actuator_state();
	}

}
