#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/KPD/KPD_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "KPD&LCD&SEG.h"
void start_All(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOB_RCC);
	LCD_voidInit();
	KPD_voidInit();
	volatile u8 key_get;
	LCD_voidSendString("Hello ");
	wait_ms(500);
	LCD_voidClearScreen();


	MDIO_voidSetPinDirection(DIOB, 8, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 9, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 10, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 11, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 12, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 13, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, 14, OUTPUT_SPEED_2MHZ_PP);


	u8 lcd_num[]={'0','1','2','3','4','5','6','7','8','9'};
	u8 sev_seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	u8 size =sizeof(lcd_num)/sizeof(lcd_num[0]);
	for(u8 i=0;i<size;i++){
		LCD_voidSendData(lcd_num[i]);
		GPIOB->ODR|=(sev_seg[i]<<8);
		wait_ms(500);
		GPIOB->ODR&=~(0xff<<8);

	}
	LCD_voidClearScreen();

	LCD_voidSendString("KPD is ready ");
	wait_ms(500);
	LCD_voidClearScreen();
	while(1){
		key_get=KPD_u8GetPresssed();
		switch (key_get){
		case 0xFF:  break;
		case '?':LCD_voidClearScreen();break;
		default:
			LCD_voidSendData(key_get);

		}


	}


	while(1){
		for(u8 j=0;j<10;j++){
			GPIOB->ODR|=(sev_seg[j]<<8);
			wait_ms(1000);
			GPIOB->ODR&=~(0xff<<8);
		}
	}
}
