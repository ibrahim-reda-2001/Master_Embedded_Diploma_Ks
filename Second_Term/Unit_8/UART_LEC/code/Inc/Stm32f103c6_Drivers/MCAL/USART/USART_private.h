/*
 * USART_private.h
 *
 *  Created on: Feb 3, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_USART_USART_PRIVATE_H_
#define STM32F103C6_DRIVERS_MCAL_USART_USART_PRIVATE_H_
/***************************** NVIC  **********************************/
#define NVIC_ISER1_USART               *((volatile u32*) 0xE000E104)
#define NVIC_ICER1_USART               *((volatile u32*) 0xE000E100+0x84)
//this for interrupt
/***************************** USART  **********************************/
#define USART1_Base             0x40013800UL
#define USART2_Base             0x40004400UL
typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_TypeDef;
#define USART1        ((USART_TypeDef *)USART1_Base)
#define USART2        ((USART_TypeDef *)USART2_Base)

#endif /* STM32F103C6_DRIVERS_MCAL_USART_USART_PRIVATE_H_ */
