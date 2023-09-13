
#ifndef STATE_H_
#define STATE_H_
#include<stdio.h>

//AUTO state function genrated
#define STATE_define(_StateFunc_) void ST_##_StateFunc_()
#define STATE(_StateFunc_)  ST_##_StateFunc_


//states connection destination
void US_set_distance( int distance);
void DC_motor_set (int speed);



#endif /* STATE_H_ */
