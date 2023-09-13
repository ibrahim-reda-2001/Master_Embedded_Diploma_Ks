#include<stdio.h>
void two_interval_prime(int num1,int num2){

int not_prime_flag=0;

for(int i=num1;i<=num2;i++){
    for(int j=2;j<i;j++){
      if(i%j==0){
       not_prime_flag=1;
       break ;
      }
    }
    if(not_prime_flag==0){
        printf("%d\t",i);
    }
    else{
      not_prime_flag=0;
    }
}


}
int main(void){

int num1,num2;
printf("Enter the two numbers(interval) start from num 2 ");
fflush(stdin);fflush(stdout);
scanf("%d%d",&num1,&num2);
if(num1==0||num1==1){
	printf("it is wrong number \n");
}
else{
two_interval_prime(num1,num2);}
        return 0;

 }
