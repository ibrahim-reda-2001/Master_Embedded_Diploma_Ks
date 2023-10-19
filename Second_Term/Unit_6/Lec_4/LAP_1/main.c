#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
#define GPIOA_BASE       0x40010800
#define GPIOA_CRH        *(volatile u32*) (0x40010800+0x04)
#define GPIOA_CRL        *(volatile u32*) (0x40010800)
#define GPIOA_ODR        *(volatile u32*) (0x40010800+0x0C)
#define RCC_BASE         0x40021000
#define RCC_CR           *(volatile u32*) (RCC_BASE) //default HSI enable
#define RCC_APB2ENR      *(volatile u32*) (0x40021018)
#define RCC_APB1ENR      *(volatile u32*) (RCC_BASE+0x1C)
#define RCC_CFGR         *(volatile u32*) (0x40021004)
#define EXTI_BASE        0x40010400
#define EXTI_IMR         *(volatile u32*) (0x40010400) //mask
#define EXTI_FTSR        *(volatile u32*) (0x4001040C) //falling edge
#define EXTI_PR          *(volatile u32*) (0x40010414) //pending write 1 to clear
#define AFIO_BASE        0x40010000
#define AFIO_EXTICR1     *(volatile u32*) (0x40010008) //enable PA0 as IQR by default 0
#define NVIC             *(volatile u32*) (0xE000E100)
void clock_init(void){


	RCC_CFGR|=(0b101<<11);//divide ABP2 by 4
	RCC_CFGR|=(0b100<<8);//divide ABP1 by 2
	RCC_CFGR|=(0b0111<<4);//divide AHB by 1(default HSI) (0b0xxx)
	RCC_APB2ENR|=(1<<2);//enable portA
	RCC_APB2ENR|=(1<<0);//enable AFIO
}
void GPIO_INIT(){

	GPIOA_CRH &=0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;
	//PINA 0 input floating
	GPIOA_CRL|=1<<2;

}
void EXTI0_IRQHandler(void){
	//TRQ is happened EXIT0 ??? PORTA pin0 ?? falling edge
	//toggle led

		GPIOA_ODR^=1<<13;
		//clear pending request to prevent processor from cycling
		EXTI_PR|=1<<0;

}

int main(void){
	clock_init();
	GPIO_INIT();
	EXTI_IMR|=1<<0;
	EXTI_FTSR|=1<<0;
	AFIO_EXTICR1=0;//BY default it is zero
//enable NVIC IRQ 6 ?? EXTI 0

	NVIC|=1<<6;
while (1);
	return 0;
}

