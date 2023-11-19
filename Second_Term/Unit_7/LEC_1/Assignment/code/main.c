
#include "MCAL/DIO/DIO_interface.h"
#include <util/delay.h>
/*********************** SEVEN SEGMENT  **************************/
#define Seven_Segment_Pin_Start               DIO_PIN4
#define Seven_segment_Port                    DIO_PORTC
#define Seven_segment_control_Port            DIO_PORTC
#define Seven_segment1_control_Pin            DIO_PIN2
#define Seven_segment2_control_Pin            DIO_PIN3
void Init_SevenSegment(){
	DIO_enumSetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC,Seven_segment1_control_Pin,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC,Seven_segment2_control_Pin,DIO_PIN_OUTPUT);
	//disable all
	DIO_enumSetPinValue(DIO_PORTC,Seven_segment1_control_Pin,DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTC,Seven_segment2_control_Pin,DIO_PIN_LOW);

}
void LED(){
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);

	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);

	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_INPUT);

}
void Buzzer(){
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);//this for switch
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_LOW);



}

int main(){
	Init_SevenSegment();
	LED();
	Buzzer();
	u8 counter=4;

	while(1){

       /********************** Three LEDs   ***********************************/
		/*for(u8 Led_Counter=5;Led_Counter<8;Led_Counter++){
			DIO_enumSetPinValue(DIO_PORTD,Led_Counter,DIO_PIN_HIGH);
			_delay_ms(2000);
		}
		for(u8 Led_Counter=7;Led_Counter>4;Led_Counter--){
			DIO_enumSetPinValue(DIO_PORTD,Led_Counter,DIO_PIN_LOW);
			_delay_ms(2000);
		}*/
	       /********************** Three LEDs switch   *************************/
/*
		if(GET_BIT(PIND_Register,DIO_PIN1)==1){

			counter++;
			while(GET_BIT(PIND_Register,DIO_PIN1)==1);
		}
		switch (counter){
		case 5:DIO_enumSetPinValue(DIO_PORTD,counter,DIO_PIN_HIGH); break;
		case 6:DIO_enumSetPinValue(DIO_PORTD,counter,DIO_PIN_HIGH); break;
		case 7:DIO_enumSetPinValue(DIO_PORTD,counter,DIO_PIN_HIGH); break;
		case 8:
			DIO_enumSetPinValue(DIO_PORTD,5,DIO_PIN_LOW);
			DIO_enumSetPinValue(DIO_PORTD,6,DIO_PIN_LOW);
			DIO_enumSetPinValue(DIO_PORTD,7,DIO_PIN_LOW);
			counter=4;
		}

*/
		/********************** Buzzer   **************************************/
		/*
if(GET_BIT(PIND_Register,0)==1){
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_LOW);
	while(GET_BIT(PIND_Register,0)==1);

}
*/
		/********************** Seven  Segments   *************************/

	/*	for(u8 c=0;c<25;c++){
		for(u8 i=0;i<10;i++){
			for(u8 j=0;j<10;j++){

				DIO_enumSetPinValue(DIO_PORTC,Seven_segment2_control_Pin,DIO_PIN_HIGH);
				PORTC_Register&=0x0f;
				PORTC_Register|=(i<<4);
				_delay_ms(100);
				DIO_enumSetPinValue(DIO_PORTC,Seven_segment2_control_Pin,DIO_PIN_LOW);
				DIO_enumSetPinValue(DIO_PORTC,Seven_segment1_control_Pin,DIO_PIN_HIGH);
				PORTC_Register&=0x0f;
				PORTC_Register|=(j<<4);
				_delay_ms(100);
			}
		}
}*/
	}
	return 0;
}
