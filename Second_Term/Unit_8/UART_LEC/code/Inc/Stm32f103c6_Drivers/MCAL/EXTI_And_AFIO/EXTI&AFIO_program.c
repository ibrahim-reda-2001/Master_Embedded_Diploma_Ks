#include "EXTI&AFIO_private.h"
#include "EXTI&AFIO_config.h"
#include "EXTI&AFIO_interface.h"

/*
 ***=========================================***
 * 					Generic variables
 */
//array of  pointer to function to 15 IRQ

void (*GP_IRQ_CallBack[15])(void);

/*
 ***=========================================***
 * 					Generic Function
 */
void Enable_NVIC(u8 IRQ){
	switch(IRQ){
	case 0:NVIC_IQR6_EXTI0_Enable;break;
	case 1:NVIC_IQR7_EXTI1_Enable;break;
	case 2:NVIC_IQR8_EXTI2_Enable;break;
	case 3:NVIC_IQR9_EXTI3_Enable;break;
	case 4:NVIC_IQR10_EXTI4_Enable;break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:NVIC_IQR23_EXTI5_9_Enable;break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:NVIC_IQR40_EXTI10_15_Enable;break;


	}
}
void Disable_NVIC(u8 IRQ){
	switch(IRQ){
		case 0:NVIC_IQR6_EXTI0_Disable;break;
		case 1:NVIC_IQR7_EXTI1_Disable;break;
		case 2:NVIC_IQR8_EXTI2_Disable;break;
		case 3:NVIC_IQR9_EXTI3_Disable;break;
		case 4:NVIC_IQR10_EXTI4_Disable;break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:NVIC_IQR23_EXTI5_9_Disable;break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:NVIC_IQR40_EXTI10_15_Disable;break;


		}
}


/***===========================================================***/

/* @FN            -MCAL_EXTI_GPIO_Disable
 * @brief         -this used to Disable EXTI and NVIC
 * @parameters    -none
 * @RetVal        - none
 * @note          - none
 */

void MEXTI_void_DEINIT(void){

	//Disable from EXTI
	EXTI->EXTI_IMR=0x00000000;
	EXTI->EXTI_EMR=0x00000000;
	EXTI->EXTI_RTSR=0x00000000;
	EXTI->EXTI_FTSR=0x00000000;
	EXTI->EXTI_SWIER=0x00000000;
	EXTI->EXTI_PR=0xFFFFFFFF;

	//Disable from NVIC
	NVIC_IQR6_EXTI0_Disable             ;
	 NVIC_IQR7_EXTI1_Disable            ;
	 NVIC_IQR8_EXTI2_Disable            ;
	 NVIC_IQR9_EXTI3_Disable            ;
	 NVIC_IQR10_EXTI4_Disable           ;
	 NVIC_IQR23_EXTI5_9_Disable         ;
	 NVIC_IQR40_EXTI10_15_Disable       ;



}



/***===========================================================***/

/* @FN            -MCAL_EXTI_GPIO_Init
 * @brief         -this used to initialize GPIO_pin and specify the mask/trigger condition and IRQ and IRQ CallBack
 * @parameters    -EXTI_Config set by @ref EXTI_Define ,EXTI_Trigger_Define and EXTI_IRQ_Define
 * @RetVal        - none
 * @note          - stm32f103c6 MCU  has GPIO A,B,C,D,E Modules
 *                 but LQFP48 package has only GPIO A,B and part of C,D exported as External PINS
 *                 -also mandatory to enable RCC clock for AFIO 	and the corresponding GPIO
 */

void MEXTI_void_INIT(EXTI_PinConfig* EXTI_Confi ){
    //1- configure GPIO to be AF -> floating input
	MDIO_voidSetPinDirection(EXTI_Confi->EXTI_PIN.PORT, EXTI_Confi->EXTI_PIN.GPIO_PIN, INPUT_FLOATING);

	//======================================================
	//2- update AFIO  to route between EXTI line with PORT A,B,C,D
	u8 test=EXTI_Confi->EXTI_PIN.ETI_InputLineNumber;
	u8 AFIO_EXTICR_Index=test/4;
	u8 AFIO_EXTICR_POS=(test%4)*4;
	//clear 4 bits
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index]&=~(0xF<<AFIO_EXTICR_POS);
	switch(EXTI_Confi->EXTI_PIN.PORT){
	case DIOA:	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index]|=(0x0<<AFIO_EXTICR_POS);break;
	case DIOB:  AFIO->AFIO_EXTICR[AFIO_EXTICR_Index]|=(0x1<<AFIO_EXTICR_POS);break;
	case DIOC:  AFIO->AFIO_EXTICR[AFIO_EXTICR_Index]|=(0x2<<AFIO_EXTICR_POS);break;
	}

	//======================================================
	//3- update Rising or Falling Register
	//check to disable
	EXTI->EXTI_RTSR&=~(1<<test);
	EXTI->EXTI_FTSR&=~(1<<test);
	if(EXTI_Confi->Trigger_Case==EXTI_Trigger_Rising){
		EXTI->EXTI_RTSR|=(1<<test);

	}
	else if(EXTI_Confi->Trigger_Case==EXTI_Trigger_Falling){
		EXTI->EXTI_FTSR|=(1<<test);

	}
	else if(EXTI_Confi->Trigger_Case==EXTI_Trigger_RisingAndFalling){
		EXTI->EXTI_RTSR|=(1<<test);
		EXTI->EXTI_FTSR|=(1<<test);
	}
	//======================================================
	//4- Update IRQ Handling CallBack
	GP_IRQ_CallBack[test]=EXTI_Confi->ptr_IRQ_CALLBACK;
	//======================================================
	//4- Enable or Disable IQR & NVIC
	if(EXTI_Confi->IRQ_EN==EXTI_IQR_Enable){
		EXTI->EXTI_IMR|=(1<<test);
		Enable_NVIC(test);

	}
	else if(EXTI_Confi->IRQ_EN==EXTI_IQR_Disable){
		EXTI->EXTI_IMR&=~(1<<test);
		Disable_NVIC(test);

	}

}



/****************************************** IRQ ************************************************************/
void EXTI0_IRQHandler(void){
//pending request clear by write 1
	EXTI->EXTI_PR|=1<<0;
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void){
	//pending request clear by write 1
		EXTI->EXTI_PR|=1<<1;
		GP_IRQ_CallBack[1]();
}
void EXTI2_IRQHandler(void){
	//pending request clear by write 1
		EXTI->EXTI_PR|=1<<2;
		GP_IRQ_CallBack[2]();
}
void EXTI3_IRQHandler(void){
	//pending request clear by write 1
		EXTI->EXTI_PR|=1<<3;
		GP_IRQ_CallBack[3]();
}
void EXTI4_IRQHandler(void){
	//pending request clear by write 1
		EXTI->EXTI_PR|=1<<4;
		GP_IRQ_CallBack[4]();
}
void EXTI9_5_IRQHandler(void){
if(EXTI->EXTI_PR&1<<5){EXTI->EXTI_PR|=1<<5;GP_IRQ_CallBack[5]();}
if(EXTI->EXTI_PR&1<<6){EXTI->EXTI_PR|=1<<6;GP_IRQ_CallBack[6]();}
if(EXTI->EXTI_PR&1<<7){EXTI->EXTI_PR|=1<<7;GP_IRQ_CallBack[7]();}
if(EXTI->EXTI_PR&1<<8){EXTI->EXTI_PR|=1<<8;GP_IRQ_CallBack[8]();}
if(EXTI->EXTI_PR&1<<9){EXTI->EXTI_PR|=1<<9;GP_IRQ_CallBack[9]();}

}
void EXTI15_10_IRQHandler(void){
	if(EXTI->EXTI_PR&1<<10){EXTI->EXTI_PR|=1<<10;GP_IRQ_CallBack[10]();}
	if(EXTI->EXTI_PR&1<<11){EXTI->EXTI_PR|=1<<11;GP_IRQ_CallBack[11]();}
	if(EXTI->EXTI_PR&1<<12){EXTI->EXTI_PR|=1<<12;GP_IRQ_CallBack[12]();}
	if(EXTI->EXTI_PR&1<<13){EXTI->EXTI_PR|=1<<13;GP_IRQ_CallBack[13]();}
	if(EXTI->EXTI_PR&1<<14){EXTI->EXTI_PR|=1<<14;GP_IRQ_CallBack[14]();}
	if(EXTI->EXTI_PR&1<<15){EXTI->EXTI_PR|=1<<15;GP_IRQ_CallBack[15]();}

}

