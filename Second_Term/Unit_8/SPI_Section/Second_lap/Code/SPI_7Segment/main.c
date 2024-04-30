#include "avr/io.h"
#include "util/delay.h"
#define MOSI   5
#define SCK    7
#define SS     4
typedef unsigned char u8;

void excute (u8 cmd , u8 data){
	PORTB&=~(1<<SS);
	SPDR=cmd;
	while(!(SPSR & (1<<SPIF)));
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
	PORTB|=(1<<SS);

}

int main(void){
	u8 counter =0;
	u8 index_dispaly=1;
	DDRB=(1<<MOSI)|(1<<SCK)|(1<<SS);
	DDRB=0xFF;
	PORTB=0xFF;
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
	excute(0x09,0xFF);//decode all display
	excute(0x0B,0x07); //set scan limit
	excute(0x0A,0x0F);//max intensity
	excute(0x0C,0x01);//turn on display

while(1){
		for (index_dispaly=1;index_dispaly<9;index_dispaly++){
			excute(index_dispaly,counter++);
		}
		_delay_ms(500);



}

	return 0;
}
