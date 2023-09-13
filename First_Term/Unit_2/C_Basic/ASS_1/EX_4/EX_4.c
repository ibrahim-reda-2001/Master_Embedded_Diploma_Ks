#include<stdio.h>
int main(void){
float x,y;
printf("Enter two numbers: ");
fflush(stdout);fflush(stdin);
scanf("%f %f",&x,&y);
printf("Product : %.3f",x*y);
return 0;
}
