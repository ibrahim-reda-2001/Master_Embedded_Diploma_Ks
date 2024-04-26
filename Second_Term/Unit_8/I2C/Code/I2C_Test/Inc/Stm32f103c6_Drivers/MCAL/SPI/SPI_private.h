/*
 * SPI_private.h
 *
 *  Created on: Mar 5, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_SPI_SPI_PRIVATE_H_
#define STM32F103C6_DRIVERS_MCAL_SPI_SPI_PRIVATE_H_
#include "../../LIP/STD_TYPES.h"
/***************************** NVIC  **********************************/
#define NVIC_ISER1_SPI               *((volatile u32*) 0xE000E104) //this for set position of SPI1 is 35->35-32=3 this for SPI1
                                                                   //this for set position of SPI2 is 36->36-32=4 this for SPI2
#define NVIC_ICER1_SPI               *((volatile u32*) 0xE000E100+0x84)//this for clear
//this for interrupt
/***************************** SPI  **********************************/
#define SPI1     (( SPI_TypeDef*) 0x40013000UL)    //connect to APB2
#define SPI2     (( SPI_TypeDef*) 0x40003800UL)    //connect to APB1

typedef struct{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
//	volatile u32 CRCPR;
//	volatile u32 RXCRCR;
//	volatile u32 TXCRCR;
//	volatile u32 I2SCFGR;
//	volatile u32 SPI_I2SPR;
}SPI_TypeDef;


#endif /* STM32F103C6_DRIVERS_MCAL_SPI_SPI_PRIVATE_H_ */
