

/******************************************************* 	MASTER        **********************************************************/

#include "avr/io.h"
#include "util/delay.h"
//#define  SPCR    *((volatile u8*)0x2D)
//#define  DDRB    *((volatile u8*)0x37)

#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7
typedef unsigned char  u8;
void SPI_Init(){
	DDRB|=(1<<SCK)|(1<<MOSI)|(1<<SS);
	DDRB&=~(1<<MISO);
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_Master_TX(u8 data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}
u8 SPI_Master_TX_RX(u8 data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void ){

	SPI_Init();
	DDRA=0xFF;
	u8 data;
	for(data=0;data<=255;data++){
		_delay_ms(1000);
		PORTA=SPI_Master_TX_RX(data);
		//PORTA=SPI_Master_Recive(data);
	}




	return 0;
}
