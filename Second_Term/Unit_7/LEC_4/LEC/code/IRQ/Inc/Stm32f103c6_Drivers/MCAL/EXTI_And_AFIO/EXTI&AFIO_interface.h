/*
 * EXTI&AFIO_interface.h
 *
 *  Created on: ١٨‏/١٢‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_INTERFACE_H_
#define STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_INTERFACE_H_
//#include "EXTI&AFIO_private.h"
#include "../DIO/DIO_interface.h"
#include "EXTI&AFIO_private.h"

/***************************** STRUCT FOR CONFIG  **********************************/
typedef struct{
	u16 ETI_InputLineNumber;
	u16 PORT;
	u16 GPIO_PIN;
	u8 IVT_IRQ;
}EXTI_GPIO_Mapping_t;

typedef struct{

	EXTI_GPIO_Mapping_t    EXTI_PIN           ;//Specific the external interrupt GPIO mapping
									           //this parameter must be set based on @REF EXTI_define
	/***************************************************************************************************/
	u8                     Trigger_Case      ;//Specifies Rising or Falling or Both
	                                          //this Parameter must be set based  on @REF EXTI_Trigger_Define
	/***************************************************************************************************/
	u8                    IRQ_EN             ;//Enable or Disable EXTI IRQ (this will enable IRQ mask in EXTI also NVIC Interrupt)
											//this parameter must be set based on @REF EXTI_IRQ define
	/***************************************************************************************************/
	void(*ptr_IRQ_CALLBACK)(void);
}EXTI_PinConfig;
//@REF EXTI_define
//this code use to save time of write
//for(int i=0;i<16;i++){
//	 printf("//EXTI%d\n",i);
//	 printf("#define EXTI%dPA%d  (EXTI_GPIO_Mapping_t){EXTI%d,DIOA,PIN%d, EXTI%d_IRQ}\n",i,i,i,i,i);
//	 printf("#define EXTI%dPB%d  (EXTI_GPIO_Mapping_t){EXTI%d,DIOB,PIN%d, EXTI%d_IRQ}\n",i,i,i,i,i);
//	 printf("#define EXTI%dPC%d  (EXTI_GPIO_Mapping_t){EXTI%d,DIOC,PIN%d, EXTI%d_IRQ}\n",i,i,i,i,i);
//	 printf("#define EXTI%dPD%d  (EXTI_GPIO_Mapping_t){EXTI%d,DIOD,PIN%d, EXTI%d_IRQ}\n",i,i,i,i,i);
// }
//EXTI0
#define EXTI0PA0  (EXTI_GPIO_Mapping_t){EXTI0,DIOA,PIN0, EXTI0_IRQ}
#define EXTI0PB0  (EXTI_GPIO_Mapping_t){EXTI0,DIOB,PIN0, EXTI0_IRQ}
#define EXTI0PC0  (EXTI_GPIO_Mapping_t){EXTI0,DIOC,PIN0, EXTI0_IRQ}
#define EXTI0PD0  (EXTI_GPIO_Mapping_t){EXTI0,DIOD,PIN0, EXTI0_IRQ}
//EXTI1
#define EXTI1PA1  (EXTI_GPIO_Mapping_t){EXTI1,DIOA,PIN1, EXTI1_IRQ}
#define EXTI1PB1  (EXTI_GPIO_Mapping_t){EXTI1,DIOB,PIN1, EXTI1_IRQ}
#define EXTI1PC1  (EXTI_GPIO_Mapping_t){EXTI1,DIOC,PIN1, EXTI1_IRQ}
#define EXTI1PD1  (EXTI_GPIO_Mapping_t){EXTI1,DIOD,PIN1, EXTI1_IRQ}
//EXTI2
#define EXTI2PA2  (EXTI_GPIO_Mapping_t){EXTI2,DIOA,PIN2, EXTI2_IRQ}
#define EXTI2PB2  (EXTI_GPIO_Mapping_t){EXTI2,DIOB,PIN2, EXTI2_IRQ}
#define EXTI2PC2  (EXTI_GPIO_Mapping_t){EXTI2,DIOC,PIN2, EXTI2_IRQ}
#define EXTI2PD2  (EXTI_GPIO_Mapping_t){EXTI2,DIOD,PIN2, EXTI2_IRQ}
//EXTI3
#define EXTI3PA3  (EXTI_GPIO_Mapping_t){EXTI3,DIOA,PIN3, EXTI3_IRQ}
#define EXTI3PB3  (EXTI_GPIO_Mapping_t){EXTI3,DIOB,PIN3, EXTI3_IRQ}
#define EXTI3PC3  (EXTI_GPIO_Mapping_t){EXTI3,DIOC,PIN3, EXTI3_IRQ}
#define EXTI3PD3  (EXTI_GPIO_Mapping_t){EXTI3,DIOD,PIN3, EXTI3_IRQ}
//EXTI4
#define EXTI4PA4  (EXTI_GPIO_Mapping_t){EXTI4,DIOA,PIN4, EXTI4_IRQ}
#define EXTI4PB4  (EXTI_GPIO_Mapping_t){EXTI4,DIOB,PIN4, EXTI4_IRQ}
#define EXTI4PC4  (EXTI_GPIO_Mapping_t){EXTI4,DIOC,PIN4, EXTI4_IRQ}
#define EXTI4PD4  (EXTI_GPIO_Mapping_t){EXTI4,DIOD,PIN4, EXTI4_IRQ}
//EXTI5
#define EXTI5PA5  (EXTI_GPIO_Mapping_t){EXTI5,DIOA,PIN5, EXTI5_IRQ}
#define EXTI5PB5  (EXTI_GPIO_Mapping_t){EXTI5,DIOB,PIN5, EXTI5_IRQ}
#define EXTI5PC5  (EXTI_GPIO_Mapping_t){EXTI5,DIOC,PIN5, EXTI5_IRQ}
#define EXTI5PD5  (EXTI_GPIO_Mapping_t){EXTI5,DIOD,PIN5, EXTI5_IRQ}
//EXTI6
#define EXTI6PA6  (EXTI_GPIO_Mapping_t){EXTI6,DIOA,PIN6, EXTI6_IRQ}
#define EXTI6PB6  (EXTI_GPIO_Mapping_t){EXTI6,DIOB,PIN6, EXTI6_IRQ}
#define EXTI6PC6  (EXTI_GPIO_Mapping_t){EXTI6,DIOC,PIN6, EXTI6_IRQ}
#define EXTI6PD6  (EXTI_GPIO_Mapping_t){EXTI6,DIOD,PIN6, EXTI6_IRQ}
//EXTI7
#define EXTI7PA7  (EXTI_GPIO_Mapping_t){EXTI7,DIOA,PIN7, EXTI7_IRQ}
#define EXTI7PB7  (EXTI_GPIO_Mapping_t){EXTI7,DIOB,PIN7, EXTI7_IRQ}
#define EXTI7PC7  (EXTI_GPIO_Mapping_t){EXTI7,DIOC,PIN7, EXTI7_IRQ}
#define EXTI7PD7  (EXTI_GPIO_Mapping_t){EXTI7,DIOD,PIN7, EXTI7_IRQ}
//EXTI8
#define EXTI8PA8  (EXTI_GPIO_Mapping_t){EXTI8,DIOA,PIN8, EXTI8_IRQ}
#define EXTI8PB8  (EXTI_GPIO_Mapping_t){EXTI8,DIOB,PIN8, EXTI8_IRQ}
#define EXTI8PC8  (EXTI_GPIO_Mapping_t){EXTI8,DIOC,PIN8, EXTI8_IRQ}
#define EXTI8PD8  (EXTI_GPIO_Mapping_t){EXTI8,DIOD,PIN8, EXTI8_IRQ}
//EXTI9
#define EXTI9PA9  (EXTI_GPIO_Mapping_t){EXTI9,DIOA,PIN9, EXTI9_IRQ}
#define EXTI9PB9  (EXTI_GPIO_Mapping_t){EXTI9,DIOB,PIN9, EXTI9_IRQ}
#define EXTI9PC9  (EXTI_GPIO_Mapping_t){EXTI9,DIOC,PIN9, EXTI9_IRQ}
#define EXTI9PD9  (EXTI_GPIO_Mapping_t){EXTI9,DIOD,PIN9, EXTI9_IRQ}
//EXTI10
#define EXTI10PA10  (EXTI_GPIO_Mapping_t){EXTI10,DIOA,PIN10, EXTI10_IRQ}
#define EXTI10PB10  (EXTI_GPIO_Mapping_t){EXTI10,DIOB,PIN10, EXTI10_IRQ}
#define EXTI10PC10  (EXTI_GPIO_Mapping_t){EXTI10,DIOC,PIN10, EXTI10_IRQ}
#define EXTI10PD10  (EXTI_GPIO_Mapping_t){EXTI10,DIOD,PIN10, EXTI10_IRQ}
//EXTI11
#define EXTI11PA11  (EXTI_GPIO_Mapping_t){EXTI11,DIOA,PIN11, EXTI11_IRQ}
#define EXTI11PB11  (EXTI_GPIO_Mapping_t){EXTI11,DIOB,PIN11, EXTI11_IRQ}
#define EXTI11PC11  (EXTI_GPIO_Mapping_t){EXTI11,DIOC,PIN11, EXTI11_IRQ}
#define EXTI11PD11  (EXTI_GPIO_Mapping_t){EXTI11,DIOD,PIN11, EXTI11_IRQ}
//EXTI12
#define EXTI12PA12  (EXTI_GPIO_Mapping_t){EXTI12,DIOA,PIN12, EXTI12_IRQ}
#define EXTI12PB12  (EXTI_GPIO_Mapping_t){EXTI12,DIOB,PIN12, EXTI12_IRQ}
#define EXTI12PC12  (EXTI_GPIO_Mapping_t){EXTI12,DIOC,PIN12, EXTI12_IRQ}
#define EXTI12PD12  (EXTI_GPIO_Mapping_t){EXTI12,DIOD,PIN12, EXTI12_IRQ}
//EXTI13
#define EXTI13PA13  (EXTI_GPIO_Mapping_t){EXTI13,DIOA,PIN13, EXTI13_IRQ}
#define EXTI13PB13  (EXTI_GPIO_Mapping_t){EXTI13,DIOB,PIN13, EXTI13_IRQ}
#define EXTI13PC13  (EXTI_GPIO_Mapping_t){EXTI13,DIOC,PIN13, EXTI13_IRQ}
#define EXTI13PD13  (EXTI_GPIO_Mapping_t){EXTI13,DIOD,PIN13, EXTI13_IRQ}
//EXTI14
#define EXTI14PA14  (EXTI_GPIO_Mapping_t){EXTI14,DIOA,PIN14, EXTI14_IRQ}
#define EXTI14PB14  (EXTI_GPIO_Mapping_t){EXTI14,DIOB,PIN14, EXTI14_IRQ}
#define EXTI14PC14  (EXTI_GPIO_Mapping_t){EXTI14,DIOC,PIN14, EXTI14_IRQ}
#define EXTI14PD14  (EXTI_GPIO_Mapping_t){EXTI14,DIOD,PIN14, EXTI14_IRQ}
//EXTI15
#define EXTI15PA15  (EXTI_GPIO_Mapping_t){EXTI15,DIOA,PIN15, EXTI15_IRQ}
#define EXTI15PB15  (EXTI_GPIO_Mapping_t){EXTI15,DIOB,PIN15, EXTI15_IRQ}
#define EXTI15PC15  (EXTI_GPIO_Mapping_t){EXTI15,DIOC,PIN15, EXTI15_IRQ}
#define EXTI15PD15  (EXTI_GPIO_Mapping_t){EXTI15,DIOD,PIN15, EXTI15_IRQ}


//@REF EXTI_Trigger_Define

#define EXTI_Trigger_Rising               0
#define EXTI_Trigger_Falling              1
#define EXTI_Trigger_RisingAndFalling     2

//@REF EXTI_IRQ define
#define EXTI_IQR_Enable                   1
#define EXTI_IQR_Disable                   0


/*****************************        IVT           **********************************/
#define    EXTI0_IRQ       6
#define    EXTI1_IRQ       7
#define    EXTI2_IRQ       8
#define    EXTI3_IRQ       9
#define    EXTI4_IRQ       10
#define    EXTI5_IRQ       23
#define    EXTI6_IRQ       23
#define    EXTI7_IRQ       23
#define    EXTI8_IRQ       23
#define    EXTI9_IRQ       23
#define    EXTI10_IRQ      40
#define    EXTI11_IRQ      40
#define    EXTI12_IRQ      40
#define    EXTI13_IRQ      40
#define    EXTI14_IRQ      40
#define    EXTI15_IRQ      40

/*****************************      CONFIG             **********************************/
#define    EXTI0           0
#define    EXTI1           1
#define    EXTI2           2
#define    EXTI3           3
#define    EXTI4           4
#define    EXTI5           5
#define    EXTI6           6
#define    EXTI7           7
#define    EXTI8           8
#define    EXTI9           9
#define    EXTI10          10
#define    EXTI11          11
#define    EXTI12          12
#define    EXTI13          13
#define    EXTI14          14
#define    EXTI15          15
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//NVIC IRQ Enable/Disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IQR6_EXTI0_Enable            (NVIC_ISER0|=(1<<6))
#define NVIC_IQR7_EXTI1_Enable            (NVIC_ISER0|=(1<<7))
#define NVIC_IQR8_EXTI2_Enable            (NVIC_ISER0|=(1<<8))
#define NVIC_IQR9_EXTI3_Enable            (NVIC_ISER0|=(1<<9))
#define NVIC_IQR10_EXTI4_Enable           (NVIC_ISER0|=(1<<10))
#define NVIC_IQR23_EXTI5_9_Enable         (NVIC_ISER0|=(1<<23))
#define NVIC_IQR40_EXTI10_15_Enable       (NVIC_ISER1|=(1<<8))//40-32=8

//Disable
#define NVIC_IQR6_EXTI0_Disable            (NVIC_ICER0|=(1<<6))
#define NVIC_IQR7_EXTI1_Disable            (NVIC_ICER0|=(1<<7))
#define NVIC_IQR8_EXTI2_Disable            (NVIC_ICER0|=(1<<8))
#define NVIC_IQR9_EXTI3_Disable            (NVIC_ICER0|=(1<<9))
#define NVIC_IQR10_EXTI4_Disable           (NVIC_ICER0|=(1<<10))
#define NVIC_IQR23_EXTI5_9_Disable         (NVIC_ICER0|=(1<<23))
#define NVIC_IQR40_EXTI10_15_Disable       (NVIC_ICER1|=(1<<8))//40-32=8

/*
 * ====================================================================================
 *                     APIs Supported by "MCAL GPIO DRIVER "
 * ====================================================================================
 */
void MEXTI_void_INIT(EXTI_PinConfig* EXTI_Confi );
void MEXTI_void_DEINIT(void );
void MEXTI_void_UPDATE(EXTI_PinConfig* EXTI_Confi );


#endif /* STM32F103C6_DRIVERS_MCAL_EXTI_AND_AFIO_EXTI_AFIO_INTERFACE_H_ */
