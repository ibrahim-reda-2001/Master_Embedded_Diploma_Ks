/*
 * Timer_2_to_5_Config.h
 *
 *  Created on: ٠٣‏/١١‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef TIMER_2_TO_5_CONFIG_H_
#define TIMER_2_TO_5_CONFIG_H_

/************* SELECT TIMER ****************/
#define  SELECTED_TIMER    TIMER2
/********************* SELECT PRESCALER ********************/
#define PRESCALER      36
//in register of prescaler f=(f"sys"/ prescaler+1) prescaler=36-1=35
/******************************************************************************
  *									PINS for channels	                				  *
  *******************************************************************************/
  /*MDIO_voidSetPinDirection(DIOA, PIN0, OUTPUT_SPEED_2MHZ_AFPP);
	MDIO_voidSetPinDirection(DIOA, PIN1, OUTPUT_SPEED_2MHZ_AFPP);
	MDIO_voidSetPinDirection(DIOA, PIN2, OUTPUT_SPEED_2MHZ_AFPP);
	MDIO_voidSetPinDirection(DIOA, PIN3, OUTPUT_SPEED_2MHZ_AFPP);
*/



#endif /* TIMER_2_TO_5_CONFIG_H_ */
