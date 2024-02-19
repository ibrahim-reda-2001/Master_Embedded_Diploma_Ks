/*
 * RCC_private.h
 *
 *  Created on: ٠٢‏/١٠‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define Base_Addresse 0x4002100

//Register definition
#define RCC_CR            *((volatile u32*)0x40021000)
#define RCC_CFGR          *((volatile u32*)0x40021004)
#define RCC_CIR           *((volatile u32*)0x40021008)
#define RCC_APB2RSTR      *((volatile u32*)0x4002100C)
#define RCC_APB1RSTS      *((volatile u32*)0x40021010)
#define RCC_AHBENR        *((volatile u32*)0x40021014)
#define RCC_APB2ENR       *((volatile u32*)0x40021018)
#define RCC_APB1ENR       *((volatile u32*)0x4002101C)
#define RCC_BDCR          *((volatile u32*)0x40021020)
#define RCC_CSR           *((volatile u32*)0x40021024)



#endif /* RCC_PRIVATE_H_ */
