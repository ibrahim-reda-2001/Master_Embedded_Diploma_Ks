#include<stdio.h>
 int main(void){
float num1,num2,num3;
printf("Enter three numbers ");
fflush(stdin);fflush(stdout);
scanf("%f %f %f",&num1,&num2,&num3);
	if((num1>num2)&&(num1>num3)){
		printf("Largest number = %f",num1);
	}
	else if((num2>num1)&&(num2>num3)){
			printf("Largest number = %f",num2);
		}
	else if((num3>num1)&&(num3>num2)){
				printf("Largest number = %f",num3);
			}
	else{
		printf(" ##Three numbers equal ##\n");
	}


	return 0;
 }
