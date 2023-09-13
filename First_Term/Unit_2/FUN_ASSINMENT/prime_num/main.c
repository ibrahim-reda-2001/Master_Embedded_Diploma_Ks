#include<stdio.h>
int main(void){
 int x;
 printf("Enter the number \n");
 fflush(stdin);fflush(stdout);
 scanf("%d",&x);
 for(int i=2;i<x/2;i++){
    if(x%i==0){
        printf("it is not prime \n");
        return 0;
    }


 }

        printf("it is  prime \n");


return 0;
}

