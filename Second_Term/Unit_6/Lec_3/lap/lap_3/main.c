#include <stdio.h>
#include <stdlib.h>
typedef unsigned int u32;
#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile u32*) (0x40010800+0x04)
#define GPIOA_ODR    *(volatile u32*) (0x40010800+0x0C)
#define RCC_BASE     0x40021000
#define RCC_CR          *(volatile u32*) (0x40021000) //default HSI enable
#define RCC_APB2ENR     *(volatile u32*) (0x40021018)
#define RCC_CFGR        *(volatile u32*) (0x40021004)


int main(void){

RCC_CFGR|=(0b10<<0);
RCC_CFGR|=(0b0110<<18);
RCC_CFGR|=(0b100<<8);
RCC_CFGR|=(0b101<<11);
RCC_CR|=(1<<24);



	
	while (1){

	}
	return 0;
}

