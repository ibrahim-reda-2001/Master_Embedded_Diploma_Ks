#include <util/delay.h>
#include "KPD_config.h"
#include "KPD_interface.h"
void KPD_voidInit(){

#if KPD_MODE==KPD_DEFAULT
	//ROWS set as internal pull up resistor
	DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R0 , DIO_PIN_INPUT );
	DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R1 , DIO_PIN_INPUT );
	DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R2 , DIO_PIN_INPUT );
	DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R3 , DIO_PIN_INPUT );

	DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R0 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R1 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R2 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R3 , DIO_PIN_HIGH );
	//COLS set as OUTPUT high
	DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C0 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C1 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C2 , DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C3 , DIO_PIN_OUTPUT );

	DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C0 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C1 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C2 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C3 , DIO_PIN_HIGH );

#elif KPD_MODE==FARES_PCB_KPD
	//ROWS set as internal pull up resistor
		DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R0 , DIO_PIN_INPUT );
		DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R1 , DIO_PIN_INPUT );
		DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R2 , DIO_PIN_INPUT );
		DIO_enumSetPinDirection( KPD_ROW_PORT , KPD_R3 , DIO_PIN_INPUT );

		DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R0 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R1 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R2 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_ROW_PORT , KPD_R3 , DIO_PIN_HIGH );
		//COLS set as OUTPUT high
		DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C0 , DIO_PIN_OUTPUT );
		DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C1 , DIO_PIN_OUTPUT );
		DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C2 , DIO_PIN_OUTPUT );
		DIO_enumSetPinDirection( KPD_COL_PORT , KPD_C3 , DIO_PIN_OUTPUT );

		DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C0 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C1 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C2 , DIO_PIN_HIGH );
		DIO_enumSetPinValue    ( KPD_COL_PORT , KPD_C3 , DIO_PIN_HIGH );

#endif
}

u8   KPD_u8GetPresssed(){
u8 LOC_u8ReturnData = NOT_PRESSED ;
u8 LOC_u8GetPressed ;
// iterators
u8 LOC_u8Row ;
u8 LOC_u8Col ;

for( LOC_u8Col = 0 + KPD_COL_INIT ; LOC_u8Col < KPD_COL_END + 1 ; LOC_u8Col++ ){

DIO_enumSetPinValue    ( KPD_COL_PORT , LOC_u8Col , DIO_PIN_LOW );   // Low on the columns

for( LOC_u8Row = 0 +KPD_ROW_INIT ; LOC_u8Row < KPD_ROW_END + 1 ; LOC_u8Row++ ){

DIO_enumGetPinValue( KPD_ROW_PORT , LOC_u8Row , &LOC_u8GetPressed ); // retun the row value

//if the row is high ....there is no pressed buttons
//if the row is low ....there is pressed button ===>> I will check on this

if( LOC_u8GetPressed == 0 )
{

	_delay_ms(50);   // delay for bouncing

	DIO_enumGetPinValue( KPD_ROW_PORT , LOC_u8Row , &LOC_u8GetPressed );   // to make sure that the button is pressed & check again

	if( LOC_u8GetPressed == 0 )

	{
		///     # Important Note #

	//	the button will khnow by the row and the column (ASCII Code)
		//==> Hint1 : I already defined The ASCII Codes in 2D array at --> "KPD_config.h"
		//==> Hint2 : if there is no pressed buttons , it will retured NOTPRESSED (0xff) and there is not any button has this ASCII (0xff)
		 //

		LOC_u8ReturnData = KPD_u8Buttons[ LOC_u8Row - KPD_ROW_INIT ][ LOC_u8Col - KPD_COL_INIT ];

	}

	// stay here if the button is pressed   # we could put delay 200 ms instead of that
	DIO_enumGetPinValue( KPD_ROW_PORT , LOC_u8Row , &LOC_u8GetPressed );
	while( DIO_PIN_LOW == LOC_u8GetPressed )//   This cond for safty instead of (LOC_u8GetPressed == DIO_PIN_LOW) if i foget =
	{

		DIO_enumGetPinValue( KPD_ROW_PORT , LOC_u8Row , &LOC_u8GetPressed );

	}

	break ;

}

}

// return this column’s pin to high
DIO_enumSetPinValue    ( KPD_COL_PORT , LOC_u8Col , DIO_PIN_HIGH );

}
return LOC_u8ReturnData ; //default 0xff so make it switch case do noting -> case 0xff: break;

}
/*u8   KPD_u8GetPresssed(){
	u8 i,j;
	u8 LOC_u8GetPressed ;

	for(i=0;i<4;i++){
		DIO_enumSetPinValue(DIO_PORTD,KPD_C0,DIO_PIN_HIGH);
		DIO_enumSetPinValue(DIO_PORTD,KPD_C1,DIO_PIN_HIGH);
		DIO_enumSetPinValue(DIO_PORTD,KPD_C2,DIO_PIN_HIGH);
		DIO_enumSetPinValue(DIO_PORTD,KPD_C3,DIO_PIN_HIGH);
		DIO_enumSetPinValue(DIO_PORTD,KPD_COL[i],DIO_PIN_LOW);
		for(j=0;j<4;j++){
			DIO_enumGetPinValue(DIO_PORTD,KPD_ROW[j],&LOC_u8GetPressed);
			if(LOC_u8GetPressed==0){
				while(LOC_u8GetPressed==0);//for bouncing
				switch (i){
				case 0:
					if(j==0)      return '7';
					else if(j==1) return '4';
					else if(j==2) return '1';
					else if(j==3) return '?';
					break;
				case 1:
					if(j==0)      return '8';
					else if(j==1) return '5';
					else if(j==2) return '2';
					else if(j==3) return '0';
					break;
				case 2:
					if(j==0)      return '9';
					else if(j==1) return '6';
					else if(j==2) return '3';
					else if(j==3) return '=';
					break;
				case 3:
					if(j==0)      return '/';
					else if(j==1) return '*';
					else if(j==2) return '-';
					else if(j==3) return '+';
					break;
				}
			}
		}


	}
	return 'A';
}*/

