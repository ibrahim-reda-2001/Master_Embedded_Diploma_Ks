#include<stdio.h>
#define size 100
#include<string.h>
int main(void){
	char arr[size];
			int counter=0;

			printf("Enter a String  : ");
			fflush(stdin);fflush(stdout);
			gets(arr);

		for(int i=0;arr[i]!='\0';i++){

				counter++;
			}
		printf("Reverse string is : ");
for(int i = counter-1 ;arr[i]!='\0';i--){
	printf("%c",arr[i]);
}




return 0;
}
