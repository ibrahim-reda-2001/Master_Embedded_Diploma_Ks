/*
 * LCD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

//  mode 8       ====> 8
// mode 4        ====> 4
// mode FARES   ====> 10

#define LCD_MODE    			4
#define LCD_DATA_PORT           DIO_PORTA
#define LCD_CONTROL_PORT        DIO_PORTA
#define LCD_RS					DIO_PIN1
#define LCD_EN				    DIO_PIN2
#define LCD_RW					DIO_PIN3
#define LCD_DATA_REG           PORTA_Register

#endif /* HAL_LCD_LCD_CONFIG_H_ */
