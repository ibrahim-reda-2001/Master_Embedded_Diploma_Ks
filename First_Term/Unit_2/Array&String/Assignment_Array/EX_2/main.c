#include<stdio.h>
#define size 100
 int main(){
float arr[size],sum=0;
int n;
printf("Enter the number of date : \n");
fflush(stdin);fflush(stdout);
scanf("%d",&n);
for(int i=0;i<n;i++){
	printf(" %d. Enter the number :  ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&arr[i]);
}
for(int i=0;i<n;i++){
	sum+=arr[i];
}
printf("Average : %.2f",sum/n);

	 return 0;
 }
