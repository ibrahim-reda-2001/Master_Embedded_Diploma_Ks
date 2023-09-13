#include<stdio.h>
int main(void){
	int arr[100];
	int size,number;
	printf("Enter the number of element \n");
	fflush(stdin);fflush(stdout);
scanf("%d",&size);
for(int i=0;i<size;i++){
	fflush(stdin);fflush(stdout);
	scanf("%d",&arr[i]);
}
 printf("Enter the elements to be searched :");
	fflush(stdin);fflush(stdout);
scanf("%d",&number);
for(int i=0;i<size;i++){
if(arr[i]==number){
	printf("Number found at the location %d " ,i+1);
	break;
}

}

	return 0;
}
