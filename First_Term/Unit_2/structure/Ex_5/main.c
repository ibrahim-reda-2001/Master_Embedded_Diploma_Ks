#include<stdio.h>
#define pi 3.14
#define area(r)  ((r)*(r)*(pi))
int main(void){
	int x;
	float y;
	printf("Enter the radius \n");
	fflush(stdout);fflush(stdout);
	scanf("%d",&x);
	y=area(x);

	printf("The area equal : %.2f \n",y);

	return 0;
}
