#include<stdio.h>
#include<string.h>
#define size 100
int main(void){
	char arr[size];
	int counter=0;
	char x;
	printf("Enter a String  : ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	printf("Enter a character to find frequency :  ");
	fflush(stdin);fflush(stdout);
scanf("%c",&x);
for(int i=0;arr[i]!='\0';i++){
	if(arr[i]==x){
		counter++;
	}

}

printf("frequency of %c = %d",x,counter);

	return 0;
}
