#include "UART_interface.h"
#include "UART_private.h"
u8 buffer;
static u8* TX_str;
static u8 flag_send;
void UART_Init(void){
	//frame
	UBRRL=51;
	//normal mode
	CLR_BIT(UCSRA,U2X);//U2X equal 1 for double speed
	//BaudRate


	//enable
	UCSRC|=Eight_Bits_Length;
	UCSRC|=Parity_None;
	UCSRC|=one_stop_Bit;
	UCSRB|=RX_TX_En;


}
void UART_Send(u8 data){
	//while(!(UCSRA&&(1<<UDRE)));
	//while(!((UCSRA&(1<<5))>>5));
		while(!(GET_BIT(UCSRA,UDRE)));
	//while(!(UCSRA & (1<<UDRE)));


	UDR=data;
}
u8 UART_Rceive(){
	//while ( !(UCSRA & (1<<RXC)) );
	//while( !(UCSRA & (1<<RXC)) );
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;
}
void UART_Send_String(char* str){
	for(u8 i=0;str[i]!='\0';i++){
		UART_Send(str[i]);
	}
	UART_Send(Default_Stop);
}
void UART_Recive_string(char* BUF){
	u8 i=0;
	BUF[i]=UART_Rceive();
	while(BUF[i]!='\r'){
		i++;
		BUF[i]=UART_Rceive();
	}
	BUF[i]='\0';
}
void UART_send_int_number(u32 num){
	u8 *ptr= (u8*)&num;
	UART_Send(ptr[0]);
	UART_Send(ptr[1]);
	UART_Send(ptr[2]);
	UART_Send(ptr[3]);

}
u32 UART_Receive_int_number(){
	u32 num;
	u8 *ptr=(u8*)&num;
	ptr[0]=UART_Rceive();
	ptr[1]=UART_Rceive();
	ptr[2]=UART_Rceive();
	ptr[3]=UART_Rceive();
	return num;
}
u8 UART_Perodic_Check_char(u8* Pdata){
	u8  ret=0;
	if(GET_BIT(UCSRA,RXC)){
		*Pdata=UDR;
		ret=1;
	}
	return ret;
}
void UART_IRQ_Send_Data(u8 data){
	data=UDR;
}
u8 UART_IRQ_Recive_Data(void){
	return UDR;
}
void UART_TX_Interrup_ENable(void){
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_Interrup_Disable(void){
	CLR_BIT(UCSRB,TXCIE);
}
void UART_RX_Interrup_ENable(void){
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_Interrup_Disable(void){
	CLR_BIT(UCSRB,RXCIE);
}
void UART_SendString_Asynch(u8* str){
	if(flag_send==1){
	UART_TX_Interrup_ENable();
	UART_IRQ_Send_Data(str[0]);
	TX_str=str;
	flag_send=0;
	}
}
void UART_ReceiveString_Asynch(u8* str){
UART_RX_Interrup_ENable();
}
void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void){
static u8 i=1;
if(TX_str[i]!=0){
	UART_IRQ_Send_Data(TX_str[i]);
	i++;
}
else{
	i=1;
	flag_send=1;
}
}

void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void){
	u8 c, buf[30], i=0;

		do {
			c = UART_IRQ_Recive_Data();		// receive character
			buf[i++]=c;             //copy character to string
		}while(c != '\r'&& i < 30);//   exit  
	  	buf[i]='\0';                //string end
}

