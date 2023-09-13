#include<stdio.h>

int main(void){
	int x,fact=1;
		printf("Enter an integer : ");
		 fflush(stdout);fflush(stdin);
	scanf("%d",&x);
	if(x>=0){
		for(int i =1;i<=x;i++){
			fact*=i;
		}
		printf(" Factorial = %d ",fact);;
	}
	else{
		printf("Erorr !! Factorial of negative dosen't exist \n");

	}

	return 0;
}
