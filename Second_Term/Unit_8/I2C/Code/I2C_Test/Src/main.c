#include "Stm32f103c6_Drivers/MCAL/RCC/RCC_interface.h"
#include "Stm32f103c6_Drivers/MCAL/EXTI_And_AFIO/EXTI&AFIO_interface.h"
#include "Stm32f103c6_Drivers/LIP/Wait_ms.h"
#include "Stm32f103c6_Drivers/HAL/LCD/LCD_interface.h"
#include "Stm32f103c6_Drivers/MCAL/USART/USART_interface.h"
#include "Stm32f103c6_Drivers/MCAL/SPI/SPI_config.h"
#include "Stm32f103c6_Drivers/MCAL/SPI/SPI_interface.h"
#include "Stm32f103c6_Drivers/HAL/EEPROM/EEPROM_Interface.h"

void clock_init(void){
	RCC_voidInitSysClock();
	//enable RCC for USART1
	RCC_voidEnablePeripheralClock(APB2_BUS, USART1_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOB_RCC);
	RCC_voidEnablePeripheralClock(APB1_BUS, I2C1_RCC);

	RCC_voidEnablePeripheralClock(APB2_BUS, AFIO_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, SPI1_RCC);


}

int main(){
 clock_init();
u8 ch1[7]={0x1,0x2,0x3,0x4,0x5,0x6,0x7};
u8 ch2[7]={0};
HAL_EEPROM_Init();
HAL_EEPROM_Write_NByte(0xAF, ch1, 7);
HAL_EEPROM_Read_NByte(0XAF, ch2, 7);

//test case 2
ch1[0]=0xA;
ch1[1]=0xB;
ch1[2]=0xC;
ch1[3]=0xD;
HAL_EEPROM_Write_NByte(0xFFF, ch1, 4);
HAL_EEPROM_Read_NByte(0XFFF, ch1, 4);




	while(1){

	}
	return 0;
}
