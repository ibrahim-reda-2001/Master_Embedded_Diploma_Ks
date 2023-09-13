#include "lifo.h"
#define array_size   5
elment_type buffer1[array_size];

int main(){
	unsigned int i,temp=0;
	LIFO_Buf_t UART_LIFO;
	//LIFO_Buf_t I2C_LIFO;
	for(i=0;i<5;i++){
		printf("%d\n",buffer1[i]);
	}

	//dynamic allocation
	//elment_type *buffer2=(elment_type*)malloc(array_size*sizeof(elment_type));
	//LIFO_init(&I2C_LIFO,buffer2,5);
	if(LIFO_init(&UART_LIFO,buffer1,5)==LIFO_no_errors){
		printf("\t\t*******LIFO init is done********* \n");}
	else if (LIFO_init(&UART_LIFO,buffer1,5)==LIFO_null) {
		printf("\t\t*******LIFO  null ********* \n");}


	printf("\n=======push=============\n");
	for(i=0;i<5;i++){
		if(LIFO_push(&UART_LIFO,i)==LIFO_no_errors){
			printf("UART_LIFO push : %d \n",i);}
		else if (LIFO_push(&UART_LIFO,i) == LIFO_null) {
			printf(" LIFO is null \n");
			break;
		}
		else if (LIFO_push(&UART_LIFO,i) == LIFO_full) {
			printf(" LIFO is full \n");
			break;
		}

	}
	LIFO_print(&UART_LIFO);



	printf("=========pop=================\n");
	for(i=0;i<5;i++){
		if(LIFO_pop(&UART_LIFO,&temp) == LIFO_no_errors){
			printf("UART_LIFO pop : %d \n",temp);
		}
		else if (LIFO_pop(&UART_LIFO,&temp) == LIFO_null) {
			printf(" LIFO is null \n");
			break;
		}
		else if (LIFO_pop(&UART_LIFO,&temp) == LIFO_full) {
			printf(" LIFO is full \n");
			break;
		}

	}
	LIFO_print(&UART_LIFO);

	return 0;
}
