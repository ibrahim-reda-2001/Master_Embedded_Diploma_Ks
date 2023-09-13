#include<stdio.h>
int main(void){
	char x;
	printf("Enter an alphabet : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);
	switch (x)
	{
		case 'a':
		case 'A':
		case 'E':
		case 'e':
		case 'i':
		case 'I':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			printf("%c  is vowel \n ",x);
			break;
		default:
			printf("%c  is  constant \n ",x);

	}

	return 0;
}
