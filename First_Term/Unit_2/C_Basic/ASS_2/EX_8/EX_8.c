#include<stdio.h>

int main(void){
	float num1,num2,result ;
	char y;
		printf("Enter operator either + or - or * or divid / :  ");
		 fflush(stdout);fflush(stdin);
	scanf("%c",&y);
	printf("Enter two operands : ");
	 fflush(stdout);fflush(stdin);
	scanf("%f %f",&num1,&num2);

	switch (y){
	case '+':
		result=num1+num2;break;
	case '-':
		result=num1-num2;break;
	case '*':
		result=num1-num2;break;
	case '/':
		result=num1-num2;break;
	default:
		printf("Errorrrrrrrrrrrrrr\n");
	}
printf("%.2f %c %.2f = %.2f",num1,y,num2,result);

	return 0;
}
