/*
 * DIO_private.h
 *
 *  Created on: ٠٥‏/١٠‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#include"STD_TYPES.h"
#define  GPIOA_BASE    0x40010800
#define  GPIOB_BASE    0x40010C00
#define  GPIOC_BASE    0x40011000
#define  GPIOD_BASE    0x40011400
#define  GPIOF_BASE    0x40011800
#define  GPIOG_BASE    0x40011C00
struct SGPIO{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
};

#define GPIOA  ((struct SGPIO*)GPIOA_BASE)
#define GPIOB  ((struct SGPIO*)GPIOB_BASE)
#define GPIOC  ((struct SGPIO*)GPIOC_BASE)
#define GPIOD  ((struct SGPIO*)GPIOD_BASE)
#define GPIOF  ((struct SGPIO*)GPIOF_BASE)
#define GPIOG  ((struct SGPIO*)GPIOG_BASE)




#endif /* DIO_PRIVATE_H_ */
