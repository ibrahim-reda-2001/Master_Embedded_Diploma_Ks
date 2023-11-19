
#include "LCD_interface.h"
#include "LCD_extra_char.h"
void LCD_voidInit(void){
#if LCD_MODE==8
_delay_ms(50);
DIO_enumSetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
DIO_enumSetPinDirection(DIO_PORTB,LCD_RS,DIO_PIN_OUTPUT);
DIO_enumSetPinDirection(DIO_PORTB,LCD_EN,DIO_PIN_OUTPUT);
DIO_enumSetPinDirection(DIO_PORTB,LCD_RW,DIO_PIN_OUTPUT);
LCD_voidSendCommand(lcd_Home);
_delay_ms(2);
LCD_voidSendCommand(0x38);
_delay_ms(2);
LCD_voidSendCommand(lcd_DisplayOn_CursorOn);
_delay_ms(2);
LCD_voidClearScreen();
_delay_ms(2);
LCD_voidSendCommand(lcd_EntryMode);
_delay_ms(2);
#elif LCD_MODE==4
    _delay_ms(60);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_EN , DIO_PIN_OUTPUT  );
	/*return home*/
	LCD_voidSendCommand( lcd_Home );
	_delay_ms(30);
	/*FUNCTION SET Command*/
	LCD_voidSendCommand( 0x28 ); // 4 Bit Mode
	_delay_ms(1);
	/* DISPLAY & Cursor (ON / OFF) Control */
	LCD_voidSendCommand( lcd_DisplayOn_CursorOn );
	_delay_ms(1);
	/* DISPLAY CLEAR */
	LCD_voidClearScreen();
	_delay_ms(1);

	/* ENTRY MODE  Set*/
	LCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(2);
#elif LCD_MODE==FARES_PCB_LCD
	 _delay_ms(60);
		DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN3,DIO_PIN_OUTPUT);
		DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
		DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
		DIO_enumSetPinDirection      (LCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
		DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_RS , DIO_PIN_OUTPUT  );
	//	DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_RW , DIO_PIN_OUTPUT  );
		DIO_enumSetPinDirection  ( LCD_CONTROL_PORT , LCD_EN , DIO_PIN_OUTPUT  );
		/*return home*/
			LCD_voidSendCommand( lcd_Home );
			_delay_ms(30);
			/*FUNCTION SET Command*/
			LCD_voidSendCommand( 0x28 ); // 4 Bit Mode
			_delay_ms(1);
			/* DISPLAY & Cursor (ON / OFF) Control */
			LCD_voidSendCommand( lcd_DisplayOn_CursorOn );
			_delay_ms(1);
			/* DISPLAY CLEAR */
			LCD_voidClearScreen();
			_delay_ms(1);

			/* ENTRY MODE  Set*/
			LCD_voidSendCommand( lcd_EntryMode );
			_delay_ms(2);
#endif

}
 void LCD_voidSendCommand(u8 copy_u8command ){
#if LCD_MODE==8
DIO_enumSetPortValue(LCD_DATA_PORT,copy_u8command);
DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_LOW);
DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
LCD_voidSendFallingEdge();


#elif LCD_MODE==4
DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_LOW);
DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
u8 value1=copy_u8command&0xF0;
	  LCD_DATA_REG&=0x0F;
	  LCD_DATA_REG|=value1;//send 4 MSB
	  LCD_voidSendFallingEdge();
	  u8 value2=copy_u8command<<4;
	  LCD_DATA_REG&=0x0F;
	  LCD_DATA_REG|=value2;//send 4 LSB
	  LCD_voidSendFallingEdge();
#elif LCD_MODE==FARES_PCB_LCD
	  DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_LOW);
	  u8 value1=copy_u8command>>1;
	  value1&=0x78;
	  LCD_DATA_REG&=0x87;
	  LCD_DATA_REG|=value1;
	  LCD_voidSendFallingEdge();
	  u8 value2=copy_u8command<<3;
	  value2&=0x78;
	  LCD_DATA_REG&=0x87;
	  LCD_DATA_REG|=value2;
	  LCD_voidSendFallingEdge();




#endif
_delay_ms(2);

 }
 void LCD_voidSendData(u8 copy_u8data){
#if LCD_MODE==8
	 DIO_enumSetPortValue(LCD_DATA_PORT,copy_u8data);
	 DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_HIGH);
	 DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
	 LCD_voidSendFallingEdge();


#elif LCD_MODE==4
	 DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_HIGH);
	 DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_PIN_LOW);
	  u8 value1=copy_u8data&0xF0;
	  LCD_DATA_REG&=0x0F;
	  LCD_DATA_REG|=value1;
	  LCD_voidSendFallingEdge();
	  u8 value2=copy_u8data<<4;
	  LCD_DATA_REG&=0x0F;
	  LCD_DATA_REG|=value2;
	  LCD_voidSendFallingEdge();
#elif LCD_MODE==FARES_PCB_LCD
	  DIO_enumSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_PIN_HIGH);
	 	  u8 value1=copy_u8data>>1;
	 	  value1&=0x78;
	 	  LCD_DATA_REG&=0x87;
	 	  LCD_DATA_REG|=value1;
	 	  LCD_voidSendFallingEdge();
	 	  u8 value2=copy_u8data<<3;
	 	  value2&=0x78;
	 	  LCD_DATA_REG&=0x87;
	 	  LCD_DATA_REG|=value2;
	 	  LCD_voidSendFallingEdge();


#endif
	 _delay_ms(2);
 }
  void LCD_voidSendFallingEdge(void)
 {
 	DIO_enumSetPinValue  ( LCD_CONTROL_PORT , LCD_EN , DIO_PIN_HIGH );
 	_delay_ms(1);
 	DIO_enumSetPinValue  ( LCD_CONTROL_PORT , LCD_EN , DIO_PIN_LOW  );
 	_delay_ms(1);
 }
  void LCD_voidClearScreen(void){
	  LCD_voidSendCommand(lcd_Clear);
	  _delay_ms(15);
  }
  void LCD_voidSendString(  u8* copy_u8ptrstring ){
	  for(int i=0;copy_u8ptrstring[i]!='\0';i++){
		  LCD_voidSendData(copy_u8ptrstring[i]);
		  if(i==15){
			  LCD_voidSetPosition(2,1);
		  }
	  }
  }
  void LCD_voidSetPosition(u8 ROW ,u8 COL){
	  //0x80 it must to know u control position
	u8 loc_u8data=0;
	  if(ROW>2||ROW<1||COL>16||COL<1){
		  loc_u8data=lcd_SetCursor;
	  }
	  else if(ROW==LCD_ROW_1){
		  loc_u8data= lcd_SetCursor+COL-1; //0x80 + COL-1
	  }
	  else if(ROW==LCD_ROW_2){
		  loc_u8data= 0x40+lcd_SetCursor+COL-1; //ADDRESSE=0x40+0x80+COL-1
		  //64 or 0x40 it is first position in second row

	  }
	  LCD_voidSendCommand(loc_u8data);
	  _delay_ms(1);

  }
  void LCD_voidSendExtraChar( u8 Copy_u8Row, u8 Copy_u8Col ){
	  u8 LOC_u8Iterator = 0 ;
	  	/* 1- Go To CGRAM            */
	  	LCD_voidSendCommand( lcd_CGRAM );  // Make AC refers to the first Place/Address at CGRAM


	  	/* 2- Draw Character in CGRAM        */
	  	/* Hint : it will be copied to DDRAM automatically */
	  	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(LCD_u8ExtraChar) / sizeof(LCD_u8ExtraChar[0]) ; LOC_u8Iterator++){

	  		LCD_voidSendData( LCD_u8ExtraChar[LOC_u8Iterator] );

	  	}


	  	/* 3- Back (AC) To DDRAM          */
	  	LCD_voidSetPosition(Copy_u8Row,Copy_u8Col);


	  	/* 4- Send Character Address */
	  	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ ){

	  		LCD_voidSendData( LOC_u8Iterator );

	  	}

  }
  /*void LCD_voidWriteStrColRow(u8* str,u8 row,u8 col){
	  LCD_voidSetPosition(row, col);
  u8 index=0;
  u8 line0=0;
  while(str[index]!='\0'&&(((row-1)*16)+(index+(col-1)))<32){
  if((((row-1)*16)+(index+(col-1)))<16){
	  LCD_voidSendData( str[index]);
  index++;
  }
  else if(((row*16)+(index+col))==16&&line0==0){
	  LCD_voidSetPosition(LCD_ROW_2, LCD_COL_1);
  line0++;
  }
  else if((((row-1)*16)+(index+(col-1)))<32&&line0==1){
	 LCD_voidSendData( str[index]);
  index++;

  }

  }
  }*/
  void LCD_voidSendChar(u8 character){

	  LCD_voidSendData(character);

  }
  void LCD_voidSendNumber(u32 Copy_u64Number ){
	  u64 LOC_u64Reversed = 1 ;

	  	if( Copy_u64Number == 0 ){ LCD_voidSendData('0'); }

	  	else{

	  		while( Copy_u64Number != 0 ){

	  			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
	  			Copy_u64Number /= 10 ;

	  		}
	  		while( LOC_u64Reversed != 1 ){

	  			LCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
	  			LOC_u64Reversed /= 10 ;

	  		}

	  	}

	  }

