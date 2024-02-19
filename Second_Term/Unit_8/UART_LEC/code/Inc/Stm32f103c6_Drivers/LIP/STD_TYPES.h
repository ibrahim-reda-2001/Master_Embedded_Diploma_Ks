/*
 * STD_TYPES.h
 *
 *  Created on: Sep 4, 2023
 *      Author: MAGIC
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef unsigned short int u16;
typedef signed int s32;
typedef signed char s8;
typedef signed long long int s64;
typedef float   f32;
typedef double f64;
typedef enum{
	false,
	true
}bool;
#define NULL 0

//Function state
#define IDLE 0
#define BUSY 1
//My state
#define OK	0
#define NOK	1
#define NULL_POINTER	2
#define BUST_STATE	3
#define TIME_OUT_STATE 4



#endif /* STD_TYPES_H_ */
