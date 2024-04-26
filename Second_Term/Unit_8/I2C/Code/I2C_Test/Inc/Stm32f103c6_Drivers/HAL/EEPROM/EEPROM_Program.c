#include "EEPROM_Interface.h"
#include "../../MCAL/I2C/I2C_Interface.h"

void HAL_EEPROM_Init(void){
	//PB6 : I2C1_SCL
	//PB7 : I2C1_SDA
	I2C_InitTypeDef I2C1CFG;
	I2C1CFG.I2C_ACK_Control=I2C_ACK_ENable;
	I2C1CFG.I2C_Speed=I2C_SCLK_SM_100K;
	I2C1CFG.I2C_Mode=I2C_Modde;
	I2C1CFG.P_Slave_Event_CallBack=NULL_POINTER;
	I2C1CFG.Stretch_Mode=I2C_Stretch_Mode_Enable;
	MCAL_I2C_Set_Pins(I2C1_Reg);
	MCAL_I2C_Init(I2C1_Reg, &I2C1CFG);

	}
u8 HAL_EEPROM_Write_NByte(u32 MemoryAddress,u8* Bytes,u8 Data_Length){
	u8 buffer[256];
	//EEPROM_Slave_Address  0x2A
	buffer[0]=(u8)(MemoryAddress>>8);//upper address
	buffer[1]=(u8)(MemoryAddress);//lower address
	for (int i=2;i<Data_Length+2;i++){
		buffer[i]=Bytes[i-2];
	}


	MCAL_I2C_Master_TX(I2C1_Reg, EEPROM_Slave_Address, buffer, Data_Length+2, With_Stop, WithoutRepeatStart);
	return 0;
}
u8 HAL_EEPROM_Read_NByte(u32 MemoryAddress,u8* DataOut,u8 Data_Length){
	u8 buffer[2];
	buffer[0]=(u8)(MemoryAddress>>8);
	buffer[1]=(u8)(MemoryAddress);
	MCAL_I2C_Master_TX(I2C1_Reg, EEPROM_Slave_Address, buffer, 2, With_Stop, WithoutRepeatStart);//this for specific address
	MCAL_I2C_Master_RX(I2C1_Reg, EEPROM_Slave_Address, DataOut, Data_Length, With_Stop, WithRepeatStart);

return 0;
}
