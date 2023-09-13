#include<stdio.h>
#include<stdint.h>
typedef volatile unsigned int vunit_32;
#define RCC_BASE      0x40021000
#define GPIOA_BASE    0x40010800
#define RCC_APBENR    *(volatile unsigned int*)(RCC_BASE+0x18)
#define GPIOA_CRH    *(volatile unsigned int*)(GPIOA_BASE+0x04)
#define GPIOA_ODR    *(volatile unsigned int*)(GPIOA_BASE+0x0c)
#define RCC_IOPAEN  (1<<2)
#define GPIOA        (1UL<<13)

typedef union {
unsigned int all_fields;
struct {
	unsigned int reserved :13;
	unsigned int p_13 :1;
}pin;


}R_ODR_T;
unsigned char g_variable[3]={1,2,3};
unsigned char const c_variable[3]={1,2,3};

volatile R_ODR_T* R_ODR=(volatile R_ODR_T*)(GPIOA_BASE+0x0c);
int main(void){
	RCC_APBENR|=RCC_IOPAEN;
	GPIOA_CRH&=0xff0fffff;
	GPIOA_CRH|=0x00200000;
	while(1){
		R_ODR->pin.p_13=1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.p_13=0;
		for(int i=0;i<5000;i++);


	}



	return 0;
}
