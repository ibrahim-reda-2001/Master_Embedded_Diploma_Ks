#include<stdio.h>

int main(void){
	int m=29;
	printf("Address of m : 0x%x \nValue of m : %d\n ",&m,m);
int *ptr=&m;
printf("Address of pointer Ptr : 0x%x \nContent of pointer Ptr : %d\n",&ptr,*ptr);
*ptr=34;
printf("Address of pointer Ptr : 0x%x \nContent of pointer Ptr : %d\n",&ptr,*ptr);
*ptr=7;
printf("Address of m : 0x%x \nValue of m : %d\n ",&m,m);

	return 0;
}
