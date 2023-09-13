#include<stdio.h>

int main(void){
	int x,sum=0;
	printf("Enter an integer : ");
	 fflush(stdout);fflush(stdin);
scanf("%d",&x);
	for(int i=0;i<=x;i++){
	sum+=i;
	}
	printf("Sum = %d ",sum);

	return 0;
}
