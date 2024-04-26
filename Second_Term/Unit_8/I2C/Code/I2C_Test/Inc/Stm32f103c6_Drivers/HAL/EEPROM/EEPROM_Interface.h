/*
 * EEPROM_Interface.h
 *
 *  Created on: ٢٥‏/٠٤‏/٢٠٢٤
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_HAL_EEPROM_EEPROM_INTERFACE_H_
#define STM32F103C6_DRIVERS_HAL_EEPROM_EEPROM_INTERFACE_H_

//EEPROM is I2C slave
#include "../../MCAL/I2C/I2C_Interface.h"

#define EEPROM_Slave_Address 0x5D //this is correct add

void HAL_EEPROM_Init(void);
u8 HAL_EEPROM_Write_NByte(u32 MemoryAddress,u8* Bytes,u8 Data_Length);
u8 HAL_EEPROM_Read_NByte(u32 MemoryAddress,u8* DataOut,u8 Data_Length);

#endif /* STM32F103C6_DRIVERS_HAL_EEPROM_EEPROM_INTERFACE_H_ */
