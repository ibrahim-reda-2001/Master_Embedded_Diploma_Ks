#include "fifo.h"
FIFO_status FIFO_init(FIFO_Buf_t* fifo ,element_type *buf , uint32_t length ){
	if(buf==NULL){
		return FIFO_null;}
	fifo->base=buf;
	fifo->count=0;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	return FIFO_no_errors;
}
FIFO_status FIFO_enqueue(FIFO_Buf_t* fifo ,element_type item  ){
	if(FIFO_check(fifo)==FIFO_null){
		return FIFO_null;}
	if(FIFO_check(fifo)==FIFO_full){
		return FIFO_full;}
	*(fifo->head)=item;
	fifo->count++;
	//circuler fifo u can't overwrite
	if(fifo->head==(fifo->base+sizeof(element_type)*fifo->length)){
		fifo->head=fifo->base;
	}
	else{
		fifo->head++;
	}

	return FIFO_no_errors;
}
FIFO_status FIFO_dequeue(FIFO_Buf_t* fifo ,element_type* item  ){
 	if(FIFO_check(fifo)==FIFO_null){
		return FIFO_null;}
	//check empty
	if(fifo->count==0)
		return FIFO_empty;
//tail still in base at first because first in first out
	*item =*(fifo->tail);
	fifo->count--;
	if(fifo->tail==(fifo->base+sizeof(element_type)*fifo->length)){
		fifo->tail=fifo->base;
	}
	else{
		fifo->tail++;
	}
	return FIFO_no_errors;
}
 FIFO_status FIFO_check(FIFO_Buf_t* fifo){
	if(!fifo->base||!fifo->head||!fifo->tail){
		return FIFO_null;}
	if(fifo->count==fifo->length){
		return FIFO_full;}
	if(fifo->count==0){
	return FIFO_empty;
	}
	return FIFO_no_errors;
}
void FIFO_print(FIFO_Buf_t* fifo){
	element_type *temp;
	int i=0;
	if(fifo->count==0){
		printf("FIFO is empty\n");
	}
	else{
		temp=fifo->tail;
		printf("\n=======fifo_print========\n");
		for(i=0;i<fifo->count;i++){
			printf("\t %x \n",*temp);
			temp++;
		}
		printf("============\n");
	}

}
