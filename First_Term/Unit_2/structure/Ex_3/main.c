#include<stdio.h>

 struct complex{
	int real;
	int img;
};

 struct complex sum(struct complex  x,struct complex  y){
	 struct complex result;
	 result.real=x.real+y.real;
	 result.img=x.img+y.img;
return result;
}
 int main(void){
	 struct complex x,y,result;
	 printf("\t\tEnter first complex number \n");
	 printf("Enter real and imaginary respectively \n");
		fflush(stdout);fflush(stdout);
scanf("%d%d",&x.real,&x.img);
printf("\t\tEnter second complex number \n");
printf("Enter real and imaginary respectively \n");

		fflush(stdout);fflush(stdout);
scanf("%d%d",&y.real,&y.img);
result=sum(x,y);
printf("The sum of complex num equal : %d +%di \n",result.real,result.img);
	 return 0;
 }
