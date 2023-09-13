#include<stdio.h>
#include<string.h>
#define size 100
int main(void){
	char arr[size];
		int counter=0;

		printf("Enter a String  : ");
		fflush(stdin);fflush(stdout);
		gets(arr);

	for(int i=0;arr[i]!='\0';i++){

			counter++;
		}

	printf("Length of String = %d",counter);
	return 0;
}
