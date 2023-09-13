#include<stdio.h>
int main(void){

	char x;
	printf("Enter the character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c : %d",x ,x);
	return 0;
}
