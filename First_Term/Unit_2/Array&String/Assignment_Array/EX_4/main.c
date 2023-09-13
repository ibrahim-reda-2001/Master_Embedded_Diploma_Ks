#include<stdio.h>
#define row_size 100
#define col_size 100
int main(){
int number,location;
int arr[100];
int size;
printf("enter the num of element : ");
fflush(stdout);fflush(stdin);
scanf("%d",&size);
  printf("enter the element \n");
fflush(stdout);fflush(stdin);
for(int i =0;i<size ;i++){
        fflush(stdout);fflush(stdin);
    scanf("%d",&arr[i]);
}
printf("Enter element  to inserted \n");
fflush(stdin);fflush(stdout);
scanf("%d",&number);
printf("Enter the location  \n");
fflush(stdin);fflush(stdout);
scanf("%d",&location);

for(int i =size-1;i>=location-1;i--){
arr[i+1]=arr[i];
}
arr[location-1]=number;


for(int i=0;i<size+1;i++){
	printf("%d ",arr[i]);
}


return 0;
}
