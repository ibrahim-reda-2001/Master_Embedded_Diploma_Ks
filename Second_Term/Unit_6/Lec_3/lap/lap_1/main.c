#include <stdio.h>
#include <stdlib.h>
 typedef unsigned int u32;
#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile u32*) (0x40010800+0x04)
#define GPIOA_ODR    *(volatile u32*) (0x40010800+0x0C)
#define RCC_BASE     0x40021000
#define RCC_CR    *(volatile u32*) (RCC_BASE) //default HSI enable
#define RCC_APB2ENR    *(volatile u32*) (0x40021018)
#define RCC_APB1ENR    *(volatile u32*) (RCC_BASE+0x1C)


 int main(void){
	 RCC_APB2ENR|=(1<<2);//enable portA
	GPIOA_CRH &=0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;

	while (1){
	GPIOA_ODR|=1<<13;
	for(int i=0;i<5000;i++);
	GPIOA_ODR &= ~ (1<<13);
	for(int i=0;i<5000;i++);
	}
	 return 0;
 }

