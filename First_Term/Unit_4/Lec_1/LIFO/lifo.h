
#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdint.h"
#define elment_type unsigned int

typedef struct {
	elment_type length;
	elment_type* base;
	elment_type* head;
	elment_type count;
}LIFO_Buf_t;
//user configuration
//select element type (uint8_t,uint16_t,uint32_t,....

typedef enum {
LIFO_no_errors,
LIFO_full,
LIFO_empty,
LIFO_null,
LIFO_not_empty
}LIFO_status;
//take array and length
LIFO_status LIFO_init(LIFO_Buf_t *LIFO_buf,elment_type *buf,elment_type length);
LIFO_status LIFO_push(LIFO_Buf_t *LIFO_buf,elment_type item);
LIFO_status LIFO_pop(LIFO_Buf_t *LIFO_buf,elment_type *item);
void LIFO_print(LIFO_Buf_t* lifo);


#endif /* LIFO_H_ */
