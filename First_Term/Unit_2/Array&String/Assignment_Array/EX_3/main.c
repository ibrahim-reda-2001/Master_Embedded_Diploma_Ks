#include<stdio.h>
#define row_size 100
#define col_size 100
 int main(){
int a,b;
int arr[row_size][col_size];
int transpose[col_size][row_size];
printf("Enter rows and cols of matrix\n");
fflush(stdin);fflush(stdout);
scanf("%d%d",&a,&b);
for(int i=0;i<a;i++){
	for(int j=0;j<b;j++){
		printf("Enter elements a%d%d : ",i+1,j+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i][j]);
	}
}
printf("Entered matrix : \n");
for(int i=0;i<a;i++){
	for(int j=0;j<b;j++){
		printf("%d ",arr[i][j]);
	}
	printf("\n");

}
for(int i=0;i<a;i++){
	for(int j=0;j<b;j++){

		transpose[j][i]=arr[i][j];
	}
}
printf("the Transpose matrix : \n");
for(int i=0;i<b;i++){
	for(int j=0;j<a;j++){

		printf("%d ",transpose[i][j]);
	}
	printf("\n");

}
	 return 0;
 }
