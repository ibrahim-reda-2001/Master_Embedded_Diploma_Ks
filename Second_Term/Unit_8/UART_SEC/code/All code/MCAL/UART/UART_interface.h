
#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"
#include "UART_private.h"
/**************** APIs  **************/
#define Default_Stop    '\r'

void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Rceive();
void UART_send_int_number(u32 num);
u32 UART_Receive_int_number();
void UART_Send_String(char* str);
void UART_Recive_string(char* str);
u8 UART_Perodic_Check_char(u8* Pdata);//to prevent CPU from stuck
void UART_IRQ_Send_Data(u8 data);
u8 UART_IRQ_Recive_Data(void);
void UART_TX_Interrup_ENable(void);
void UART_TX_Interrup_Disable(void);
void UART_RX_Interrup_ENable(void);
void UART_RX_Interrup_Disable(void);
//synchronous function  do it's function and return
//asynchronous function   interrupt control it and not return
void UART_SendString_Asynch(u8* str);
void UART_ReceiveString_Asynch(u8* str);



/**************** select Parity  **************/
#define Parity_None   (u8)(0)
#define Parity_Even   (u8)(1<<5)
#define Parity_Odd   (u8)(1<<5|1<<4)
/**************** select Mode  **************/
#define Asynchronous_Mode      (u8)(0)
#define Synchronous_Mode       (u8)(1<<6)
/**************** PayLoad Length  **************/
#define Five_Bits_Length       (u8)(0)
#define Six_Bits_Length       (u8)(1<<1)
#define Seven_Bits_Length       (u8)(1<<2)
#define Eight_Bits_Length       (u8)(1<<1|1<<2)
/**************** Stop Bits  **************/
#define one_stop_Bit        (u8)(0)
#define two_stop_Bit        (u8)(1<<3)
/**************** RX & TX  **************/
#define RX_Interrupt_En    (u8)(1<<7)
#define TX_Interrupt_En    (u8)(1<<6)
#define DR_Interrupt_En    (u8)(1<<5)
#define RX_En              (u8)(1<<4)
#define TX_En              (u8)(1<<3)
#define RX_TX_En           (u8)(1<<3|1<<4)
/**************** pooling  **************/

#define enable       1
#define disable      0

#endif /* MCAL_UART_UART_INTERFACE_H_ */
