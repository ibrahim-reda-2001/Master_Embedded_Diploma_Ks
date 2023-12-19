/*
 * KPD_config.h
 *
 *  Created on: ??�/??�/????
 *      Author: MAGIC
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_





u8 KPD_u8Button[4][4]={/*      C0  C1 C2  C3 */
		                 /*R0*/{'7','8','9','/'},
		                 /*R1*/{'4','5','6','*'},
                         /*R2*/{'1','2','3','-'},
                         /*R3*/{'?','0','=','+'}
                                               };

#define KPD_PORT    DIOA
#define KPD_R0      PIN0
#define KPD_R1      PIN1
#define KPD_R2      PIN2
#define KPD_R3      PIN3
#define KPD_C0      PIN4
#define KPD_C1      PIN5
#define KPD_C2      PIN6
#define KPD_C3      PIN7



#endif /* HAL_KPD_KPD_CONFIG_H_ */
