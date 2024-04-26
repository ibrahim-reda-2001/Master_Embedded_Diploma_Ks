/*
 * BIT_MATH.h
 *
 *  Created on: Sep 4, 2023
 *      Author: MAGIC
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)	reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)	reg^=(1<<bit)
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)	(reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)	((reg&(1<<bit))>>bit)


#endif /* BIT_MATH_H_ */
