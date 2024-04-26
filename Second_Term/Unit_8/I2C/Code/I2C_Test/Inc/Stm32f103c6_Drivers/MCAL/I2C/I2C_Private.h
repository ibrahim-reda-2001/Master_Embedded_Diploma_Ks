/*
 * I2C_Private.h
 *
 *  Created on: Apr 17, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_I2C_I2C_PRIVATE_H_
#define STM32F103C6_DRIVERS_MCAL_I2C_I2C_PRIVATE_H_
#include "../../LIP/STD_TYPES.h"

#define NVIC_ISER1_I2C               *((volatile u32*) 0xE000E104) //this to set interrupt write 1
#define NVIC_ICER1_I2C               *((volatile u32*) 0xE000E100+0x84)//this for clear write 1 to clear
#define NVIC_ISER0_I2C               *((volatile u32*) 0xE000E100+0x0)//this for I2C 1
#define NVIC_ICER0_I2C               *((volatile u32*) 0xE000E100+0x80)

#define I2C1_Base        0x40005400
#define I2C2_Base        0x40005800


typedef struct{
	volatile u32 I2C_CR1;
	volatile u32 I2C_CR2;
	volatile u32 I2C_OAR1;
	volatile u32 I2C_OAR2;
	volatile u32 I2C_DR;
	volatile u32 I2C_SR1;
	volatile u32 I2C_SR2;
	volatile u32 I2C_CCR;
	volatile u32 I2C_TRISE;
}I2C_TypeDef;


#define I2C1_Reg        ((I2C_TypeDef *)I2C1_Base)
#define I2C2_Reg        ((I2C_TypeDef *)I2C2_Base)






#endif /* STM32F103C6_DRIVERS_MCAL_I2C_I2C_PRIVATE_H_ */
