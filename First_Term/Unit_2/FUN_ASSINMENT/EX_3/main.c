#include<stdio.h>
void reverse(){
char x;
scanf("%c",&x);
if(x!='\n'){
    reverse();
    printf("%c",x);
}

}
int main(void){
setvbuf(stdout, NULL, _IONBF, 0);
setvbuf(stderr, NULL, _IONBF, 0);
printf("Enter the sentence \n");

reverse();


return 0;
}
