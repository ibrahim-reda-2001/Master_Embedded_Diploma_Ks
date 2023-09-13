
#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include "stdint.h"
// select element type (uint8_t,uint16_t,uint32_t,.....
//default 1 byte
#define element_type  unsigned int

//FIFI data types
typedef struct {
	element_type length;
	element_type* base;
	element_type* head;
	element_type count;
	element_type *tail;

}FIFO_Buf_t;
#define array_size 5

typedef enum {
	FIFO_no_errors,
	FIFO_full,
	FIFO_empty,
	FIFO_null,
	FIFO_not_empty
}FIFO_status;
//APIS
FIFO_status FIFO_init(FIFO_Buf_t* fifo ,element_type *buf , uint32_t length );
FIFO_status FIFO_enqueue(FIFO_Buf_t* fifo ,element_type item  );
FIFO_status FIFO_dequeue(FIFO_Buf_t* fifo ,element_type* item  );
FIFO_status FIFO_check(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);




#endif /* FIFO_H_ */
