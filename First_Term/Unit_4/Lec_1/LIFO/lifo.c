//APIS
#include "lifo.h"


LIFO_status LIFO_init(LIFO_Buf_t *LIFO_buf,elment_type *buf,elment_type length){
	if(!buf ||!LIFO_buf->head||!LIFO_buf->base ){
		return LIFO_null;
	}
	LIFO_buf->base=buf;
	LIFO_buf->head=buf;
	LIFO_buf->count=0;
	LIFO_buf->length=length;
return LIFO_no_errors;

}
LIFO_status LIFO_push(LIFO_Buf_t *LIFO_buf,elment_type item){
	if(!LIFO_buf->head||!LIFO_buf->base ){
			return LIFO_null;
		}
	//if(LIFO_buf->head>=(LIFO_buf->base+sizeof(elment_type)*length)
	if(LIFO_buf->count==LIFO_buf->length)
		return LIFO_full;

	*(LIFO_buf->head)=item;
	LIFO_buf->head++;
	LIFO_buf->count++;
	return LIFO_no_errors;
}
LIFO_status LIFO_pop(LIFO_Buf_t *LIFO_buf,elment_type* item){
	if(!LIFO_buf->head||!LIFO_buf->base ){
				return LIFO_null;
			}
	if(LIFO_buf->count==0)
		return LIFO_empty;
	LIFO_buf->head --;
	*item=*(LIFO_buf->head);
	LIFO_buf->count--;
	return LIFO_no_errors;


}
void LIFO_print(LIFO_Buf_t* lifo){
	elment_type *temp;
	int i=0;
	if(lifo->count==0){
		printf("\n\t LIFO is empty\n");
	}
	else{
		temp=lifo->head;
		temp--;
		printf("\n=======lifo_print======== \n");
		for(i=0;i<lifo->count;i++){
			printf("\t %x \n",*temp);
			temp--;
		}
		printf("============\n");
	}

}
