/*
 * main.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_

//Includes
#include "state.h"

//Defines
#define Pthreshold 20  //select Pressure threshold value in bars

//State IDs
enum{
	High_Pressure_Check
}Main_Algorithm_state_id;


//Prototypes
STATE_DEFINE(High_Pressure_Check);


//State pointer
void (*Main_Algorithm_state)();


#endif /* MAIN_ALG_H_ */
