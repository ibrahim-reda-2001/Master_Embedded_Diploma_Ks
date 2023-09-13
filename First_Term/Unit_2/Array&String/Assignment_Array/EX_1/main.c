#include<stdio.h>
#define mat1_size  2
#define mat2_size  2

 int main(){

	 float x[mat1_size][mat2_size];
	 float y[mat1_size][mat2_size];
	 float sum[mat1_size][mat2_size];
printf("Enter the elements of 1st matrix\n");

for (int i=0;i<mat1_size;i++){
	for (int j=0;j<mat2_size;j++){
		printf("Enter a%d%d ",i+1,j+1);
		fflush(stdout);fflush(stdin);
scanf("%f",&x[i][j]);

	}

}
printf("Enter the elements of 2st matrix\n");

for (int i=0;i<mat1_size;i++){
	for (int j=0;j<mat2_size;j++){
		printf("Enter a%d%d ",i+1,j+1);
		fflush(stdout);fflush(stdin);
scanf("%f",&y[i][j]);

	}
}
for (int i=0;i<mat1_size;i++){
		for (int j=0;j<mat2_size;j++){
			sum[i][j]=y[i][j]+x[i][j];

		}

	}

printf("The sum of matrix :\n");
	for (int i=0;i<mat1_size;i++){
		for (int j=0;j<mat2_size;j++){
			printf("%.1f  ",sum[i][j]);

		}
		printf("\n");
	}

	 return 0;
 }
