

/******************************************************* 	SLAVE        **********************************************************/

#include "avr/io.h"
#include "util/delay.h"
//#define  SPCR    *((volatile u8*)0x2D)
//#define  DDRB    *((volatile u8*)0x37)

#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7
typedef unsigned char  u8;
void SPI_Slave_Init(){
	DDRB|=(1<<MISO);
	DDRB&=~(1<<MOSI);
	DDRB&=~(1<<SS);
	DDRB&=~(1<<SCK);
	SPCR = (1<<SPE);
}
u8 SPI_Slave_Recive(u8 data){
	while(!(SPSR & (1<<SPIF)));

	data= SPDR;
	return data;
}
u8 SPI_Slave_TX_RX(u8 data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void ){

	SPI_Slave_Init();
	DDRA=0xFF;
	u8 data;
	for(data=255;data>0;data--){
		_delay_ms(1000);
		PORTA=SPI_Slave_TX_RX(data);
	}




	return 0;
}


