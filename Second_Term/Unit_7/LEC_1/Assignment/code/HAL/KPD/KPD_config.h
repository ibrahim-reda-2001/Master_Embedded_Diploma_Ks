/*
 * KPD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: MAGIC
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#include "../../LIP/STD_TYPES.h"


                         /* C0   C1  C2  C3  */
u8 KPD_u8Buttons[4][4] = {    {7,8,9,'/'}, /* Row0 */
						      {4,5,6,'*'}, /* Row1 */
						      {1,2,3,'-'}, /* Row2 */
						      {'?',0,'=','+'}  /* Row3 */};




#define KPD_DEFAULT     1
#define FARES_PCB_KPD       2

//  FARES_PCB_KPD   KPD_DEFAULT
#define KPD_MODE    FARES_PCB_KPD





#endif /* HAL_KPD_KPD_CONFIG_H_ */
