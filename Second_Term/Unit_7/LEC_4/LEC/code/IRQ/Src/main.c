#include "Stm32f103c6_Drivers/MCAL/RCC/RCC_interface.h"
#include "Stm32f103c6_Drivers/MCAL/EXTI_And_AFIO/EXTI&AFIO_interface.h"
#include "Stm32f103c6_Drivers/LIP/Wait_ms.h"
#include "Stm32f103c6_Drivers/HAL/LCD/LCD_interface.h"
int IRQ_Flag=0;




void EXTI9_CallBack(void){
IRQ_Flag=1;
LCD_voidSetPosition(1, 4);
LCD_voidSendString("IRQ EXTI9");
LCD_voidSetPosition(2, 1);
LCD_voidSendString("is happened _|-");

wait_ms(3000);
}

int main(){
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS, AFIO_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOB_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOA_RCC);
	LCD_voidInit();
	EXTI_PinConfig EXTI_cfg;
	/********************* EXTI9PB9 ****************************/
//	EXTI_cfg.EXTI_PIN=EXTI9PB9;
	/*==========================================================*/

	/********************* EXTI9PA9 ****************************/
		EXTI_cfg.EXTI_PIN=EXTI9PA9;
	/*==========================================================*/
	EXTI_cfg.Trigger_Case=EXTI_Trigger_Falling;
	EXTI_cfg.ptr_IRQ_CALLBACK=EXTI9_CallBack;
	EXTI_cfg.IRQ_EN=EXTI_IQR_Enable;
	MEXTI_void_INIT(&EXTI_cfg);

	IRQ_Flag=1;
	while(1){
		if(IRQ_Flag){
			LCD_voidClearScreen();
			IRQ_Flag=0;
		}
	}

	return 0;
}
