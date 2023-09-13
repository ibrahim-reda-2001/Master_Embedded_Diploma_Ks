#include"uart.h"
unit8 string_buffer[100]="learn-in-depth: ibrahim";
unit8 const string_buffer2[100]="hello rodata";


int main(void){
	Uart_Send_String(string_buffer);
	
	
	return 0;
}