#include "fifo.h"
element_type uart_buffer[array_size];

int main(){
	element_type i,temp=0;

	FIFO_Buf_t uart_fifo;
	if(FIFO_init(&uart_fifo,uart_buffer,5)==FIFO_no_errors){
		printf("\tFIFo Init***** done:)\n ");}
	else if (FIFO_init(&uart_fifo,uart_buffer,5)==FIFO_null) {
		printf("\t\t*******LIFO  null ********* \n");}
	printf("=======enqueue=============\n");

	for(i=0;i<6;i++){
		printf("FIFO enqueue (%x) \n",i);
		if(FIFO_enqueue(&uart_fifo,i)==FIFO_no_errors){
			printf("FIFO enqueue ---------- Done \n ");}

		else{
			printf("FIFO enqueue ---------- Failed \n ");

		}
	}
	FIFO_print(&uart_fifo);

	if(FIFO_dequeue(&uart_fifo,&temp)==FIFO_no_errors){
		printf("FIFO dequeue %d  ---------- Done \n ",temp);}
	if(FIFO_dequeue(&uart_fifo,&temp)==FIFO_no_errors){
		printf("FIFO enqueue %d  ---------- Done \n ",temp);}

	FIFO_print(&uart_fifo);

	return 0;
}


