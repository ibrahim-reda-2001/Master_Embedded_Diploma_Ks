#include"uart.h"

#define UART0DR   *((volatile unit32*)(unit32*)0x101f1000)
void Uart_Send_String(unsigned char *p_tx_string){
	
while(*p_tx_string != '\0'){
UART0DR=(unit32)*p_tx_string;
p_tx_string++;
}
}	