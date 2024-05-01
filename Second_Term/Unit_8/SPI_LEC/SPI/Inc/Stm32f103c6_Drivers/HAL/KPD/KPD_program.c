#include "../../LIP/Wait_ms.h"
#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

void KPD_voidInit(){

	//ROWS set as internal pull up resistor
	MDIO_voidSetPinDirection(KPD_PORT,KPD_R0,INPUT_PULLUP_PULLDOWN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_R1,INPUT_PULLUP_PULLDOWN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_R2,INPUT_PULLUP_PULLDOWN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_R3,INPUT_PULLUP_PULLDOWN);
	MDIO_voidSetPinValue(KPD_PORT,KPD_R0,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_R1,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_R2,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_R3,DIO_HIGH);
	//COLS set as OUTPUT high
	MDIO_voidSetPinDirection(KPD_PORT,KPD_C0,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_C1,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_C2,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_C3,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinValue(KPD_PORT,KPD_C0,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_C1,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_C2,DIO_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_C3,DIO_HIGH);




}
u8   KPD_u8GetPresssed(){

	u8 LOC_u8ReturndData =NOT_PRESSED;
	//u8 LOC_u8GetPressed;
	u8 LOC_u8ROW=0;
	u8 LOC_u8Col=4;
	for (LOC_u8Col=0+PIN4;LOC_u8Col<PIN7+1;LOC_u8Col++){
		MDIO_voidSetPinValue(KPD_PORT,LOC_u8Col,DIO_LOW);
		//low in COLS
		for (LOC_u8ROW=0+PIN0;LOC_u8ROW<PIN3+1;LOC_u8ROW++){

			//if the row is high    not pressed
			//if row is low         pressed
			if(MDIO_u8GetPinValue(KPD_PORT, LOC_u8ROW)==0){
				wait_ms(50);
				if(MDIO_u8GetPinValue(KPD_PORT, LOC_u8ROW)==0){
				LOC_u8ReturndData=KPD_u8Button[LOC_u8ROW-PIN0][LOC_u8Col-PIN4];
			}
			while(MDIO_u8GetPinValue(KPD_PORT, LOC_u8ROW)==0);
			break;
			}
		}
		MDIO_voidSetPinValue(KPD_PORT,LOC_u8Col,DIO_HIGH);
	}
	return LOC_u8ReturndData;
}


