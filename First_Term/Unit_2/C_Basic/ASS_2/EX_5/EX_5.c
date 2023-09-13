#include<stdio.h>
 int main(void){
	 char a;
	 printf("Enter a character : ");
	 fflush(stdout);fflush(stdin);
	 scanf("%c",&a);
	 if(((a>=97)&&(a<=122))||((a>=65)&&(a<=90))){
		 printf("%c is alphabet ",a);
	 }
	 else {
		 printf("%c is not alphabet ",a);

	 }
 }
