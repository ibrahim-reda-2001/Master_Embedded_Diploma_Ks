#include "Wait_ms.h"

void wait_ms(u32 time){
	u32 i,j;
	for(i=0;i<time;i++){
		for(j=0;j<255;j++);
	}
}
