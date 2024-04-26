#include "../../LIP/Wait_ms.h"
#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"
#define null (void*)0
/*
 * =====================================================
 *                Generic Variables
 * =====================================================
 */

USART_Config* GL_USART_Config=null;


/*
 *
 * =================================================================
 *                       APIs OF USART
 * ====================================================================
 *
 */
//BaudRATE Calculation
//USART_DIV=fclk/16*baudrate
//USARTDIV*100=fclk*25/4*baudrate
//DIV_Mantissa_mul_100=(intger part of div)*100
//mantissa equal =(integer)USART_div
//DIV_Fraction=((USARTDIV_mul_100-div_mantissa*100)*16)/100
#define USARTDIV(baudrate,clock)               (u32)(clock/(16*baudrate))
#define USARTDIV_Mul100(baudrate,clock)        (u32)((clock*25)/(4*baudrate))
#define Mantissa_Mul100(baudrate,clock)        (u32)(USARTDIV(baudrate,clock)*100)
#define Mantissa(baudrate,clock)               (u32)(USARTDIV(baudrate,clock))
#define Div_Fraction(baudrate,clock)           (u32)(((USARTDIV_Mul100(baudrate,clock)-100*USARTDIV(baudrate,clock))*16)/100)
#define USART_BRR_Register(baudrate,clock)      ((Mantissa(baudrate,clock)) <<4)|(Div_Fraction(baudrate,clock)&0xf)



/* =========================
 * @fn                  -MCAL_USART_INIT
 * @brief               -Initialize USART (ASYNCH)
 * @param[in]           -USARTx : where x is 1,2,.........
 * @param[in]           - USARTCongig: all USART configuration
 * @retval              -NONE
 * note                 -support now for ASYNCH
 */
void MCAL_USART_Init(USART_TypeDef* USARTx,USART_Config* USARTConfig,u32 clock ){
	GL_USART_Config=	USARTConfig;//this for backup
	u32 BRR;
	 //Enable USART Module
	//Bit 13 UE: USART enable
	USARTx->CR1|=(1<<13);
	//Enable USART TX and RX according to configuration item
	USARTx->CR1|=USARTConfig->USART_Mode;
	//PayLoad Width
	USARTx->CR1|=USARTConfig->PayLoad_length;
	//Parity control bits
	USARTx->CR1|=USARTConfig->USART_parity;
	//Stop control Bits
	USARTx->CR1|=USARTConfig->USART_Stop_Bits;
	//calculate BAUDRATE
	BRR=USART_BRR_Register(USARTConfig->BaudRate,clock);
	USARTx->BRR=BRR;
	//IRQ Enable/Disable
	if(USARTConfig->IRQ_Enable!=USART_IRQ_Enable_NONE){
		USARTx->CR1|=USARTConfig->IRQ_Enable;
		//Enable NVIC
				if(USARTx==USART1){
					USART1_IRQ_Enable;
				}
				else if(USARTx==USART2){
					USART2_IRQ_Enable;
				}


	}


}
void MCAL_USART_DeInit(USART_TypeDef* USARTx ){
//disable clock
	if(USARTx==USART1){
				USART1_IRQ_Disable;
			}
			else if(USARTx==USART2){
				USART2_IRQ_Disable;

			}
}
void MCAL_USART_SendDate(USART_TypeDef* USARTx,u16* TXdata,enum polling_mechnism PollingEn){
//wait until TXE_flag is set with 1
	if(PollingEn==enable){
		while(!(USARTx->SR&1<<7));
	}
	if(GL_USART_Config->PayLoad_length==USART_PayLoad_Length_9bits){
		USARTx->DR=(*TXdata&(u16)0x01FF);
	}
	else if(GL_USART_Config->PayLoad_length==USART_PayLoad_Length_8bits){
			USARTx->DR=(*TXdata&(u8)0xFF);
		}
}
void MCAL_USART_ReceiveDate(USART_TypeDef* USARTx,u16* RXdata,enum polling_mechnism PollingEn){
	//wait until RXNE_flag is set with 1
		if(PollingEn==enable){
			while(!(USARTx->SR&1<<5));
		}
		//check if payload 8 or 9 bits
		if(GL_USART_Config->PayLoad_length==USART_PayLoad_Length_9bits){
			if(GL_USART_Config->USART_parity==USART_Parity_None){
				//if no parity all buffer is data
				*((u16*)RXdata)=USARTx->DR;
		}
			else{
				*((u16*)RXdata)=USARTx->DR & (u8)0xFF;
			}
		}

		else if(GL_USART_Config->PayLoad_length==USART_PayLoad_Length_8bits){
			if(GL_USART_Config->USART_parity==USART_Parity_None){
							//if no parity all buffer is data
							*((u16*)RXdata)=USARTx->DR & (u8)0xFF;
					}
						else{
							*((u16*)RXdata)=(USARTx->DR & (u8)0x7f);
						}
		}



}


//call back function
//ISR
void USART1_IRQHandler(void){
	GL_USART_Config->P_IRQ_CallBack();
}
void USART2_IRQHandler(void){

}

