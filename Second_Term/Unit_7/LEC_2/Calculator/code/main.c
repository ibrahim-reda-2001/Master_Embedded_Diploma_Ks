#include "HAL/LCD/LCD_interface.h"
#include "HAL/KPD/KPD_interface.h"
/*********************** Operation Functions **************************/
u32 arrayToNumber(u32 arr[], u8 size) {
	int result = 0;

	for (int i = 0; i < size; i++) {
		result = result * 10 + arr[i];
	}

	return result;
}
u8 check_password(u8 *arr1,u8 *arr2,u8 size){
	u8 check=0;
	u8 ret;
	for(u8 i=0;i<size;i++){
		if(arr1[i]==arr2[i]){
			check++;
		}
		else if(arr1[i]!=arr2[i]){
			check=0;
			break;
		}
	}
	if(check==size){
		ret=1;
	}
	else{
		ret=0;
	}
	return ret;

}
#define size    5
u32 first_number[size];
u32 second_number[size];
u32 fnum=0;
u32 Snum=0;
#define Password_size        10
#define check_password_size  10
u8 num_of_pass=0;
u8 Password[Password_size];
u8 CheckPassword[check_password_size];
int main(void){
	LCD_voidInit();
	KPD_voidInit();
	DIO_enumSetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	u8 key;
	//set password
	LCD_voidSendString("Set Password ");
	while(1){
		do{
			key=KPD_u8GetPresssed();

		}
		while(key==0xff);

		if(key=='?'){

			break;
		}
		LCD_voidSetPosition(2,num_of_pass+1);
		LCD_voidSendNumber(key);
		_delay_ms(100);
		LCD_voidSetPosition(2,num_of_pass+1);
		LCD_voidSendChar('*');//this put * in number u write
		Password[num_of_pass]=key;//this array to store password
		num_of_pass++;
	}
	u8 check_pass_counter=0;

	while(1){
		LCD_voidClearScreen();
		key=0xFF;
		_delay_ms(100);
		LCD_voidSendString("Check Password");
		while(key!='?'){ /*********************** Check Password  *************************/

			do{
				key=KPD_u8GetPresssed();

			}
			while(key==0xff);

			if(key=='?'){
				check_pass_counter=0;

				break;
			}
			LCD_voidSetPosition(2,check_pass_counter+1);
			LCD_voidSendNumber(key);
			_delay_ms(200);
			LCD_voidSetPosition(2,check_pass_counter+1);
			LCD_voidSendChar('*');
			CheckPassword[check_pass_counter]=key;//this array store password to compare
			check_pass_counter++;
		}
		if(check_password(CheckPassword,Password,check_password_size)){
			//function to compare password array with password check and return 1 if equal
			while(1){
			LCD_voidClearScreen();
			u8 operation =0;//to which operation chosen
			LCD_voidSetPosition(1,5);
			LCD_voidSendString("Mastering");
			LCD_voidSetPosition(2,5);
			LCD_voidSendString("Embedded ");
			_delay_ms(500);
			LCD_voidClearScreen();
			LCD_voidSetPosition(1,3);
			LCD_voidSendString("Calculator ");
			_delay_ms(500);
			LCD_voidClearScreen();

			/********************** getting first number ******************/
			u8	counter1=1;
			u8 arr_counter1=0;
			while(1){
				do{
					key=KPD_u8GetPresssed();

				}
				while(key==0xff);

				if(key=='+'||key=='*'||key=='-'||key=='/'){
					operation=key;//this used for switch case
					LCD_voidSetPosition(1,counter1);
					LCD_voidSendChar(key);
					break;
				}

				first_number[arr_counter1]=key; //this array to store number u enter
				//fnum=fnum*10+key;
				LCD_voidSetPosition(1,counter1);
				LCD_voidSendNumber(key);
				counter1++;
				arr_counter1++;
			}

			//Getting second number
			u8 counter2=counter1+1;
			u8 arr_counter2=0;

			while(1){
				do{
					key=KPD_u8GetPresssed();

				}
				while(key==0xff);

				if(key=='='){
					LCD_voidSetPosition(1,counter2);

					LCD_voidSendChar(key);
					break;
				}

				second_number[arr_counter2]=key;
				//Snum=Snum*10+key;
				LCD_voidSetPosition(1,counter2);
				LCD_voidSendNumber(key);
				counter2 ++;
				arr_counter2++;
			}

			u32 number1 =arrayToNumber(first_number,arr_counter1);//this function to transfer array to number {1,2,3} => 123
			u32 number2 =arrayToNumber(second_number,arr_counter2);
			/********************** switch cases for operator ***************************/
			switch(operation){
			case '*':LCD_voidSetPosition(1,counter2+1);LCD_voidSendNumber(number1*number2);  break;
			case '/': LCD_voidSetPosition(1,counter2+1);
			if(number2==0){
				LCD_voidSendString("Infinity");
			}
			else{

				LCD_voidSendNumber(number1/number2);} break;
			case '-': LCD_voidSetPosition(1,counter2+1);
			if(number2>number1){
				LCD_voidSendChar('-');
				LCD_voidSetPosition(1,counter2+2);
				LCD_voidSendNumber(number2-number1);

			}
			else{
				LCD_voidSendNumber(number1-number2);} break;
			case '+': LCD_voidSetPosition(1,counter2+1);LCD_voidSendNumber(number1+number2); break;

			}
			_delay_ms(1500);
			LCD_voidClearScreen();
		}
		}
		else{

			LCD_voidClearScreen();
			LCD_voidSendString("Wrong Password");
			DIO_enumSetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
			_delay_ms(500);
			DIO_enumSetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);

			_delay_ms(1000);
			LCD_voidClearScreen();
			LCD_voidSendString("Try Again");
			_delay_ms(1000);
			//this to reset array after wrong password
			//to ensure it empty
			for(u8 i=0;i<check_password_size;i++){
				CheckPassword[i]=0;
			}
		}

	}

	return 0;
}
