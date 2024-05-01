/*
 * USART_interface.h
 *
 *  Created on: Feb 3, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_USART_USART_INTERFACE_H_
#define STM32F103C6_DRIVERS_MCAL_USART_USART_INTERFACE_H_
#include "../../LIP/STD_TYPES.h"
#include "USART_private.h"

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//         IVT
//_*_*_*_*_*_*_*_*_*_*_*_*_*
#define    USART1_IRQ      (u32)37
#define    USART2_IRQ      (u32)38


//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//NVIC IRQ Enable/Disable  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*
#define USART1_IRQ_Enable  NVIC_ISER1_USART|=(1<<5)//37-32=5
#define USART2_IRQ_Enable  NVIC_ISER1_USART|=(1<<6)//38-32=6

#define USART1_IRQ_Disable  NVIC_ICER1_USART|=(1<<5)//37-32=5
#define USART2_IRQ_Disable  NVIC_ICER1_USART|=(1<<6)//38-32=6
//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       USART Configuration
//_*_*_*_*_*_*_*_*_*_*_*_*_*
typedef struct{
	u8				USART_Mode;           		      //specifies RX/TX Enable/Disable
								          	  	     //this parameters must be based on @ref USART_Mode_Define

	u32				BaudRate;     			        //this parameter configure USAR baudrate
								   	   	   	       //this parameters must be based on @ref USART_BaudRate_Define

	u8				PayLoad_length;    		      //specifies number of bits transmitter or receive
								   	   	   	     //this parameters must be based on @ref USART_PayLoad_length_Define

	u8				USART_parity;    		    //specifies the parity mode
									 	 	   //this parameters must be based on @ref USART_Parity_Define

	u8				USART_Stop_Bits;  		  //specifies the number of stop bits
									 	 	 //this parameters must be based on @ref USART_Stop_Bits_Define

	u8				IRQ_Enable;            //Enable or disable Interrupt
										  //this parameters must be based on @ref USART_IRQ_Define

	void(* P_IRQ_CallBack)(void)          ; //pointer to callback function in application layer

}USART_Config;
//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       Reference  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*

//@ref USART_Mode_Define

#define  USART_Mode_RX         (u32)(1<<2) //Bit 2 RE: Receiver enable
#define  USART_Mode_TX     	  (u32)(1<<3) //Bit 3 TE: Transmitter enable
#define  USART_Mode_RX_and_TX      ((u32)((1<<2)|(1<<3)))
//@ref USART_BaudRate
#define USART_BaudRate_2400           2400
#define USART_BaudRate_9600           9600
#define USART_BaudRate_19200          19200
#define USART_BaudRate_57600          57600
#define USART_BaudRate_115384         115384
#define USART_BaudRate_230769         230769
#define USART_BaudRate_461538         461538
#define USART_BaudRate_923076         923076
#define USART_BaudRate_2250000        2250000
#define USART_BaudRate_4500000        4500000

//@ref USART_PayLoad_length_Define

// Program the M bit in USART_CR1 to define the word length.
//Bit 12 M: Word length
//0: 1 Start bit, 8 Data bits, n Stop bit
//1: 1 Start bit, 9 Data bits, n Stop bit
#define USART_PayLoad_Length_8bits    (u32)0
#define USART_PayLoad_Length_9bits   (u32)(1<<12)
//@ref USART_Parity_Define

//Bit 9 PS: Parity selection
//0: Even parity
//1: Odd parity
#define USART_Parity_None         (u32)(0)
#define USART_Even_Parity_Bits    (u32)(1<<10)
#define USART_Odd_Parity_Bits     (u32)(1<<10|1<<9)
//take care of selecting parity
//This bit selects the hardware parity control (generation and detection). When the parity
//control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
//if M=0) and parity is checked on the received data. This bit is set and cleared by software.
//Once it is set, PCE is active after the current byte (in reception and in transmission).

//@ref USART_Stop_Bits_Define

//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
#define USART_Stop_BITS_half_bit                     (u32)(1<<12)
#define USART_Stop_BITS_one_bit		                 (u32)(0)
#define USART_Stop_BITS_two_bit		                 (u32)(2<<12)
//#define USART_Stop_BITS_one_half_bit		         (u32)(3<<12)

//@ref USART_IRQ_Define

#define USART_IRQ_Enable_NONE           (u32)(0)
#define USART_IRQ_Enable_TXE            (u32)(1<<7) //transmitter data REG empty
#define USART_IRQ_Enable_TC             (u32)(1<<6) //transmission complete
#define USART_IRQ_Enable_RXNEIE         (u32)(1<<5) //Received data ready to be read
#define USART_IRQ_Enable_PE             (u32)(1<<8) //parity error

/*
 *
 * =================================================================
 *                       APIs OF USART
 * ====================================================================
 *
 */
enum polling_mechnism{
	enable,
	disable
};
void MCAL_USART_Init(USART_TypeDef* USARTx,USART_Config* USARTConfig,u32 clock );
void MCAL_USART_DeInit(USART_TypeDef* USARTx);
void MCAL_USART_SendDate(USART_TypeDef* USARTx,u16* data,enum polling_mechnism PollingEn);//date may be 8 or 9 bits
void MCAL_USART_ReceiveDate(USART_TypeDef* USARTx,u16* data,enum polling_mechnism PollingEn);//date may be 8 or 9 bits




#endif /* STM32F103C6_DRIVERS_MCAL_USART_USART_INTERFACE_H_ */
