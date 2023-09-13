#include<stdio.h>
#include<string.h>
int main(void){
	char name[20];
	char Rev_name[20];

	char *ptr=name;
	char *Rev_Ptr=Rev_name;
	printf("enter string\n");
	fflush(stdin);fflush(stdout);
	scanf("%s",name);
int len=0;
while(*ptr){
ptr++;
	len++;
}
while(len>=0){
	ptr--;

	*Rev_Ptr=*ptr;
	Rev_Ptr++;
	--len;
}
*Rev_Ptr='\0';
printf("reverse : %s \n",Rev_name);

	return 0;
}
