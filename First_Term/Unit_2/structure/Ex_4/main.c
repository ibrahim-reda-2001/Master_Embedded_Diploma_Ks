#include<stdio.h>
#include<string.h>
#define number_of_students  3
struct student{
int roll;
float marks;
char name[50];
};
int main(void){
struct student students[10];
for(int i=0;i<number_of_students;i++){
printf("\t\tEnter the information of students number %d \n",i+1);
printf("Enter roll number : ");
fflush(stdout);fflush(stdout);
scanf("%d",&students[i].roll);
printf("Enter name number : ");
fflush(stdout);fflush(stdout);
scanf("%s",students[i].name);
printf("Enter marks number :");
fflush(stdout);fflush(stdout);
scanf("%f",&students[i].marks);
}
for(int i=0;i<number_of_students;i++){
	printf("\t\tDisplaying informations of student number %d \n",i+1);
	printf("name : %d \n",students[i].roll);
printf("name : %s \n",students[i].name);
printf("marks : %.2f \n",students[i].marks);

}

return 0;
}
