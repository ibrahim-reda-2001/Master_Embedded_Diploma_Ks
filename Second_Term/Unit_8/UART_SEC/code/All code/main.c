#include "util/delay.h"
#include "MCAL/UART/UART_interface.h"
#include "HAL/LCD/LCD_interface.h"

u8 x=0;
u8 y=0;
int main(void){
	UART_Init();
	LCD_voidInit();
	//char str_buffer[20];
	u8 data;
	while(1){
		//	LCD_voidClearScreen();
		//LCD_voidSetPosition(1,1);
		//	UART_Recive_string(str_buffer);
		//	LCD_voidSendString(str_buffer);
		if(UART_Perodic_Check_char(&data)){
			LCD_voidSetPosition(1,1);
			LCD_voidSendData(data);
		}
		LCD_voidSetPosition(2,1);
		LCD_voidSendNumber(x);
		x++;
		if(x==10){
			x=0;
		}
//		_delay_ms(500);
	}
}
