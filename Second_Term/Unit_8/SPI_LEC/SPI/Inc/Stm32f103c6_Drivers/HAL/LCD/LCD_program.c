#include "../../LIP/Wait_ms.h"
#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
void LCD_voidInit(void){
#if LCD_MODE==8
wait_ms(50);
MDIO_voidSetPortDirection(LCD_DATA_PORT,DIO_LOW,OUTPUT_SPEED_10MHZ_PP);
MDIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS,OUTPUT_SPEED_10MHZ_PP);
MDIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_EN,OUTPUT_SPEED_10MHZ_PP);
MDIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW,OUTPUT_SPEED_10MHZ_PP);
LCD_voidSendCommand(lcd_Home);
wait_ms(2);
LCD_voidSendCommand(0x38);
wait_ms(2);
LCD_voidSendCommand(lcd_DisplayOn_CursorOn);
wait_ms(2);
LCD_voidClearScreen();
wait_ms(2);
LCD_voidSendCommand(lcd_EntryMode);
wait_ms(2);
#elif LCD_MODE==4
wait_ms(60);
MDIO_voidSetPinDirection      (LCD_DATA_PORT,PIN4,OUTPUT_SPEED_2MHZ_PP);
MDIO_voidSetPinDirection      (LCD_DATA_PORT,PIN5,OUTPUT_SPEED_2MHZ_PP);
MDIO_voidSetPinDirection      (LCD_DATA_PORT,PIN6,OUTPUT_SPEED_2MHZ_PP);
MDIO_voidSetPinDirection      (LCD_DATA_PORT,PIN7,OUTPUT_SPEED_2MHZ_PP);
MDIO_voidSetPinDirection  ( LCD_CONTROL_PORT , LCD_RS , OUTPUT_SPEED_2MHZ_PP  );
MDIO_voidSetPinDirection  ( LCD_CONTROL_PORT , LCD_RW , OUTPUT_SPEED_2MHZ_PP  );
MDIO_voidSetPinDirection  ( LCD_CONTROL_PORT , LCD_EN , OUTPUT_SPEED_2MHZ_PP  );
	/*return home*/
	LCD_voidSendCommand( lcd_Home );
	wait_ms(30);
	/*FUNCTION SET Command*/
	LCD_voidSendCommand( 0x28 ); // 4 Bit Mode
	wait_ms(1);
	/* DISPLAY & Cursor (ON / OFF) Control */
	LCD_voidSendCommand( lcd_DisplayOn_CursorOn );
	wait_ms(1);
	/* DISPLAY CLEAR */
	LCD_voidClearScreen();
	wait_ms(1);

	/* ENTRY MODE  Set*/
	LCD_voidSendCommand( lcd_EntryMode );
	wait_ms(2);
#endif

}
 void LCD_voidSendCommand(u8 copy_u8command ){
#if LCD_MODE==8
MDIO_voidSetPortValue(LCD_DATA_PORT, DIO_LOW, copy_u8command);
MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
LCD_voidSendFallingEdge();


#elif LCD_MODE==4
MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
u8 value1=copy_u8command&0xF0;
	  GPIOB->ODR&=0x0F;
	  GPIOB->ODR|=value1;//send 4 MSB
	  LCD_voidSendFallingEdge();
	  u8 value2=copy_u8command<<4;
	  GPIOB->ODR&=0x0F;
	  GPIOB->ODR|=value2;//send 4 LSB
	  LCD_voidSendFallingEdge();
#endif
wait_ms(2);

 }
 void LCD_voidSendData(u8 copy_u8data){
#if LCD_MODE==8
	 MDIO_voidSetPortValue(LCD_DATA_PORT, DIO_LOW, copy_u8data);
	 MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	 MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	 LCD_voidSendFallingEdge();


#elif LCD_MODE==4
	 MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	 MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	  u8 value1=copy_u8data&0xF0;
	  GPIOB->ODR&=0x0F;
	  GPIOB->ODR|=value1;
	  LCD_voidSendFallingEdge();
	  u8 value2=copy_u8data<<4;
	  GPIOB->ODR&=0x0F;
	  GPIOB->ODR|=value2;
	  LCD_voidSendFallingEdge();

#endif
	 wait_ms(2);
 }
  void LCD_voidSendFallingEdge(void)
 {
	  MDIO_voidSetPinValue  ( LCD_CONTROL_PORT , LCD_EN , DIO_HIGH );
 	wait_ms(1);
 	MDIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN , DIO_LOW );
 	wait_ms(1);
 }
  void LCD_voidClearScreen(void){
	  LCD_voidSendCommand(lcd_Clear);
	  wait_ms(15);
  }
  void LCD_voidSendString(  char* copy_u8ptrstring ){
	  for(int i=0;copy_u8ptrstring[i]!='\0';i++){
		  LCD_voidSendData(copy_u8ptrstring[i]);
		  if(i==14){
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
	  wait_ms(1);

  }
