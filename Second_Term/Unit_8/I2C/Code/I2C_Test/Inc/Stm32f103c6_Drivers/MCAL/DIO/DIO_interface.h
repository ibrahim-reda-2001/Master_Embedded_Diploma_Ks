/*
 * DIO_interface.h
 *
 *  Created on: ٠٥‏/١٠‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIP/STD_TYPES.h"
/**************** PORT DIRECTION ************/
#define DIO_HIGH	1
#define DIO_LOW		0
/**************** SELECT PORT ************/
#define DIOA        1
#define DIOB        2
#define DIOC	    3
/**************** SELECT PINS ************/
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15
/**************** PINS MODE ************/
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 50
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

/**************** INTERFACE ************/

void MDIO_voidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin, u8 u8Copy_u8Mode);
void MDIO_voidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin,u8 u8Copy_u8Value);
u8   MDIO_u8GetPinValue        ( u8 Copy_u8Port , u8 Copy_u8Pin);
void MDIO_voidSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode);
void MDIO_voidSetPortValue     ( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value);








#endif /* DIO_INTERFACE_H_ */
