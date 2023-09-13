#include<stdio.h>
int main(void){
	/*setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);*/
	int x;
	printf("Enter a integer : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);
	printf("You entered : %d ", x);
return 0;
}
