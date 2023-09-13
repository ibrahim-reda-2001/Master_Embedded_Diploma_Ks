#include<stdio.h>
 struct distance{
	 int feet;
	 float inch;
 };

 int main(void){
	 struct distance d1,d2,sum;
	 printf("\t\t Enter information for first distance \n");
	 printf("Enter feet : ");
		fflush(stdout);fflush(stdout);
scanf("%d",&d1.feet);
printf("Enter inch : ");
		fflush(stdout);fflush(stdout);
scanf("%f",&d1.inch);
printf("\t\t Enter information for second distance \n");
	 printf("Enter feet : ");
		fflush(stdout);fflush(stdout);
scanf("%d",&d2.feet);
printf("Enter inch : ");
		fflush(stdout);fflush(stdout);
scanf("%f",&d2.inch);

sum.feet=d1.feet+d2.feet;
sum.inch=d1.inch+d2.inch;
if(sum.inch>12.0){
	sum.inch-=12;
	sum.feet++;
}
printf("sum of distance = %d '-%.2f' ",sum.feet,sum.inch);

	 return 0;
 }
