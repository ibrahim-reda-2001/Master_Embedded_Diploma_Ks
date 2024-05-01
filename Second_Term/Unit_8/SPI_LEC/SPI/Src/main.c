#include "Stm32f103c6_Drivers/MCAL/RCC/RCC_interface.h"
#include "Stm32f103c6_Drivers/MCAL/EXTI_And_AFIO/EXTI&AFIO_interface.h"
#include "Stm32f103c6_Drivers/LIP/Wait_ms.h"
#include "Stm32f103c6_Drivers/HAL/LCD/LCD_interface.h"
#include "Stm32f103c6_Drivers/MCAL/USART/USART_interface.h"
#include "Stm32f103c6_Drivers/MCAL/SPI/SPI_config.h"
#include "Stm32f103c6_Drivers/MCAL/SPI/SPI_interface.h"
u32 clock_init(void){
	RCC_voidInitSysClock();
	//enable RCC for USART1
	RCC_voidEnablePeripheralClock(APB2_BUS, USART1_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, AFIO_RCC);
//	RCC_voidEnablePeripheralClock(APB2_BUS, SPI1_RCC);
	u32 clock =RCC_u32GetPClk1Freq();//this clock used to calculate baudrate of USART1
	//u32 clock =RCC_u32GetPClk2Freq();//this clock used to calculate baudrate of USART2

	return clock;
}


u16 ch;



void Ibrahim_Interrup(void){

	MCAL_USART_ReceiveDate(USART1, &ch, disable);
	MCAL_USART_SendDate(USART1, &ch, enable);
	//send to SPI
	u16 ch2=(u8)ch;

	MDIO_voidSetPinValue(DIOA, PIN4, DIO_LOW);
	MCAL_SPI_Send_Data(SPI1, (u16*)&ch2, SPI_polling_enable);
	MDIO_voidSetPinValue(DIOA, PIN4, DIO_HIGH);
}
int main(){
	//without interrupt
	/*
	u32 clock_of_usart=clock_init();
	USART_Config USART_TEST;
	USART_TEST.BaudRate=USART_BaudRate_9600;
	USART_TEST.IRQ_Enable=USART_IRQ_Enable_NONE;
	USART_TEST.P_IRQ_CallBack=(void*)0;
	USART_TEST.USART_parity=USART_Parity_None;
	USART_TEST.PayLoad_length=USART_PayLoad_Length_8bits;
	USART_TEST.USART_Stop_Bits=USART_Stop_BITS_one_bit;
	USART_TEST.USART_Mode=USART_Mode_RX_and_TX;
	MCAL_USART_Init(USART1, &USART_TEST, clock_of_usart);
while(1){
	MCAL_USART_ReceiveDate(USART1, &ch, enable);
	MCAL_USART_SendDate(USART1, &ch, enable);

}
	 */

	//with interrupt
	u32 clock_of_usart=clock_init();

	//USART1_IRQ_Enable;
	USART_Config USART_TEST;
	USART_TEST.BaudRate=USART_BaudRate_9600;
	USART_TEST.IRQ_Enable=USART_IRQ_Enable_RXNEIE;
	USART_TEST.P_IRQ_CallBack=Ibrahim_Interrup;
	USART_TEST.USART_parity=USART_Parity_None;
	USART_TEST.PayLoad_length=USART_PayLoad_Length_8bits;
	USART_TEST.USART_Stop_Bits=USART_Stop_BITS_one_bit;
	USART_TEST.USART_Mode=USART_Mode_RX_and_TX;
	MDIO_voidSetPinDirection(DIOA, PIN9, OUTPUT_SPEED_10MHZ_AFPP);//Transmitter
	MDIO_voidSetPinDirection(DIOA, PIN10, INPUT_FLOATING);//Receiver
	MCAL_USART_Init(USART1, &USART_TEST, clock_of_usart);

	SPI_config SPI_CFG;

	SPI_CFG.Clock_Phase=SPI_Clock_Phase_2EDGE_First_Data_Captur_Edge;
	SPI_CFG.Clock_Polarity=SPI_Clock_Polarity_HIGH_idle;
	SPI_CFG.Data_Size=SPI_DataSize_8Bit;
	SPI_CFG.Frame_Format=SPI_Frame_Format_MSB;
	SPI_CFG.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_8;
	SPI_CFG.Device_Mode=SPI_Device_Mode_Master;
	SPI_CFG.IRQ_Enable=SPI_IRQ_Enable_None;
	SPI_CFG.NSS=SPI_NSS_SoftWare_Master_or_Slave_Set;
	SPI_CFG.Ptr_IRQ_CallBack=NULL_POINTER;

	MCAL_SPI_Init(SPI1, &SPI_CFG);
	MCAL_SPI_Set_Pins(SPI1);/*****************************/

	//set pins as (master or slave)
	//configure SS by software PA4
	MDIO_voidSetPinDirection(DIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	MDIO_voidSetPinValue(DIOA, PIN4, DIO_HIGH);

	while(1){


	}
	return 0;
}
