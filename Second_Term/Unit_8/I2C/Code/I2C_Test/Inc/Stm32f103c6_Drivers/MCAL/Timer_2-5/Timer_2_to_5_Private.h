/*
 * Timer_2_to_5_Private.h
 *
 *  Created on: ٠٣‏/١١‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef TIMER_2_TO_5_PRIVATE_H_
#define TIMER_2_TO_5_PRIVATE_H_

#include "../../LIP/STD_TYPES.h"

#define TIMER2_BASE     0x40000000
#define TIMER3_BASE	    0x40000400
#define TIMER4_BASE		0x40000800
#define TIMER5_BASE		0x40000C00
 /******************* REGISTERS ********************/

/******************************************************************************
 *									STRUCT	                				  *
 *******************************************************************************/

struct S_TIMER{
	volatile u32 TIM_CR1;
	volatile u32 TIM_CR2;
	volatile u32 TIM_SMCR;
	volatile u32 TIM_DIER;
	volatile u32 TIM_SR;
	volatile u32 TIM_EGR;
	volatile u32 TIM_CCMR1_OC;
	volatile u32 TIM_CCMR2_OC;
	volatile u32 TIM_CCER;
	volatile u32 TIM_CNT;
	volatile u32 TIM_PSC;
	volatile u32 TIM_ARR;
	volatile u32 TIM_Reserved_1;
	volatile u32 TIM_CCR1;
	volatile u32 TIM_CCR2;
	volatile u32 TIM_CCR3;
	volatile u32 TIM_CCR4;
	volatile u32 TIM_Reserved_2;
	volatile u32 TIM_DCR;
	volatile u32 TIM_DMAR;
};

#define TIMER_2   ((struct S_TIMER*)TIMER2_BASE)
#define TIMER_3   ((struct S_TIMER*)TIMER3_BASE)
#define TIMER_4   ((struct S_TIMER*)TIMER4_BASE)
#define TIMER_5   ((struct S_TIMER*)TIMER5_BASE)



#endif /* TIMER_2_TO_5_PRIVATE_H_ */
