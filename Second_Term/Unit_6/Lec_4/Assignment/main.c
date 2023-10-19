#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR (INT0_vect){
	PORTD|=(1<<7);
	_delay_ms(3000);
	PORTD&=~(1<<7);
	_delay_ms(200);

}
ISR (INT1_vect){
	PORTD|=(1<<6);
	_delay_ms(3000);
	PORTD&=~(1<<6);
	_delay_ms(200);

}
ISR (INT2_vect){
	PORTD|=(1<<5);
	_delay_ms(3000);
	PORTD&=~(1<<5);
	_delay_ms(200);

}
void init_INT(void){
	SREG&=~(1<<SREG_I);//DISABLE GLOABLE INT
	/************* INT0 ************/
	MCUCR|=(1<<ISC00); //INT0 any logical change EDGE
	GICR|=(1<<6);//enable INT0
	/************* INT1 ************/
	MCUCR|=(1<<ISC11)|(1<<ISC10); //INT1 any rising edge change EDGE
	GICR|=(1<<7);//enable INT1
	/************* INT2 ************/
	//MCUCR|=(1<<ISC00); //INT2 any falling edge change EDGE
	GICR|=(1<<5);//enable INT2

	SREG|=(1<<SREG_I);//enable GLOABLE INT


}

int main(void){
	init_INT();
	DDRD|=(1<<7);//set pin7 as output
	DDRD|=(1<<6);//set pin6 as output
	DDRD|=(1<<5);//set pin5 as output

	DDRD&=~(1<<2);//INT0 as input pin
	DDRD&=~(1<<3);//INT1 as input pin
	DDRB&=~(1<<2);//INT2 as input pin

	PORTD&=~(1<<7);//pin value output 0

	while(1){

	}

	return 0;
}
