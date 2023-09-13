#include<stdio.h>
int fact(int x){
    if(x==0){
        return 1;
    }
    else{
return x * fact(x-1);
    }
}

int main(void){
int x;
printf("Enter positive integer number\n");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
printf("Factorial of %d equal %d",x,fact(x));

        return 0;

 }

