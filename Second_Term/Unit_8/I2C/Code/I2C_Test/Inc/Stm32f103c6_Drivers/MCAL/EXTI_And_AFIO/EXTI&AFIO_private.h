/*
 * EXTI&AFIO_private.h
 *
 *  Created on: ١٨‏/١٢‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_PRIVATE_H_
#define STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_PRIVATE_H_
/***************************** INCLUDS  **********************************/
#include "../../LIP/STD_TYPES.h"

/***************************** AFIO  **********************************/
#define AFIO_BASE   0x40010000UL
struct SAFIO{
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
	u32 AFIO_RESERVED;
	u32 AFIO_MAPR2;
};
#define AFIO  ((struct SAFIO*)0x40010000)

/***************************** EXTI  **********************************/
#define EXTI_BASE  0x40010400UL
struct SEXTI{
volatile	u32 EXTI_IMR;
volatile	u32 EXTI_EMR;
volatile	u32 EXTI_RTSR;
volatile	u32 EXTI_FTSR;
volatile	u32 EXTI_SWIER;
volatile	u32 EXTI_PR;
};
#define EXTI   ((struct SEXTI*)0x40010400)

/***************************** NVIC  **********************************/
#define NVIC_BASE                0xE000E100UL
#define NVIC_ISER0               *((volatile u32*) 0xE000E100+0x0)
#define NVIC_ISER1               *((volatile u32*) 0xE000E100+0x4)
#define NVIC_ISER2               *((volatile u32*) 0xE000E100+0x8)
#define NVIC_ICER0               *((volatile u32*) 0xE000E100+0x80)
#define NVIC_ICER1               *((volatile u32*) 0xE000E100+0x84)
#define NVIC_ICER2               *((volatile u32*) 0xE000E100+0x88)

#endif /* STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_PRIVATE_H_ */
