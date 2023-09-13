#include<stdio.h>
struct information{
	char name[50];
	int roll;
	float marks;
};
int main(void){
	struct information student1;
	printf("\t\tEnter info of students \n");
	printf("Enter the name : ");
	fflush(stdout);fflush(stdout);
	scanf("%s",student1.name);
	printf("Enter the roll : ");
		fflush(stdout);fflush(stdout);
		scanf("%d",&student1.roll);
		printf("Enter the marks : ");
		fflush(stdout);fflush(stdout);
		scanf("%f",&student1.marks);
printf("Displaying Information\n");
printf("name : %s \n",student1.name);
printf("roll : %d\n",student1.roll);
printf("name : %.2f\n",student1.marks);


	return 0;
}
