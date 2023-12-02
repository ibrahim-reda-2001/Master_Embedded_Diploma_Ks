/*
 * KPD_interfacing.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"



/*
 	 Options:-

 	 	 1-DIO_PORTA
 	 	 2-DIO_PORTB
 	 	 3-DIO_PORTC
 	 	 4-DIO_PORTD

 */
#if KPD_MODE==KPD_DEFAULT
#define KPD_ROW_PORT  DIO_PORTD
#define KPD_COL_PORT  DIO_PORTD

#define KPD_ROW_INIT  DIO_PIN0
#define KPD_ROW_END   DIO_PIN3

#define KPD_COL_INIT  DIO_PIN4
#define KPD_COL_END   DIO_PIN7
/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define KPD_R0    DIO_PIN0
#define KPD_R1    DIO_PIN1
#define KPD_R2    DIO_PIN2
#define KPD_R3    DIO_PIN3

#define KPD_C0    DIO_PIN4
#define KPD_C1    DIO_PIN5
#define KPD_C2    DIO_PIN6
#define KPD_C3    DIO_PIN7

#elif KPD_MODE==FARES_PCB_KPD

#define KPD_ROW_PORT  DIO_PORTB
#define KPD_COL_PORT  DIO_PORTD

#define KPD_ROW_INIT  4
#define KPD_ROW_END   7

#define KPD_COL_INIT  2
#define KPD_COL_END   5
/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define KPD_R0    DIO_PIN4
#define KPD_R1    DIO_PIN5
#define KPD_R2    DIO_PIN6
#define KPD_R3    DIO_PIN7

#define KPD_C0    DIO_PIN2
#define KPD_C1    DIO_PIN3
#define KPD_C2    DIO_PIN4
#define KPD_C3    DIO_PIN5

#endif


#define NOT_PRESSED   0xFF
void KPD_voidInit(void);
u8   KPD_u8GetPresssed();


#endif /* HAL_KPD_KPD_INTERFACE_H_ */
