#include<stdio.h>

int main(void){
char start='A';
char *ptr=&start;
while(*ptr<='Z'){
	printf("%c ", *ptr);
	(*ptr)++;
}

	return 0;
}
