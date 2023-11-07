#include"DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "BIT_MATH.h"
void MDIO_voidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin, u8 u8Copy_u8Mode)
{
switch(Copy_u8Port)	{
case DIOA:
	if(Copy_u8Pin<=7){
	GPIOA->CRL&=~(0b1111<<4*Copy_u8Pin)	;//bcause reset value not equal zero
	GPIOA->CRL|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;
	}
	else if(Copy_u8Pin>7&&Copy_u8Pin<=15){
		Copy_u8Pin-=8;
		GPIOA->CRH&=~(0b1111<<4*Copy_u8Pin)	;
		GPIOA->CRH|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;

	}

	break;

case DIOB:
	if(Copy_u8Pin<=7){
		GPIOB->CRL&=~(0b1111<<4*Copy_u8Pin)	;//bcause reset value not equal zero
		GPIOB->CRL|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;
		}
		else if(Copy_u8Pin>7&&Copy_u8Pin<=15){
			Copy_u8Pin-=8;
			GPIOB->CRH&=~(0b1111<<4*Copy_u8Pin)	;
			GPIOB->CRH|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;

		}


	break;

case DIOC:
	if(Copy_u8Pin<=7){
		GPIOC->CRL&=~(0b1111<<4*Copy_u8Pin)	;//bcause reset value not equal zero
		GPIOC->CRL|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;
		}
		else if(Copy_u8Pin>7&&Copy_u8Pin<=15){
			Copy_u8Pin-=8;
			GPIOC->CRH&=~(0b1111<<4*Copy_u8Pin)	;
			GPIOC->CRH|=(u8Copy_u8Mode<<4*Copy_u8Pin)	;
		}
	break;
}
}
void MDIO_voidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin,u8 u8Copy_u8Value){

	switch(Copy_u8Port){
	case DIOA:
		if(u8Copy_u8Value==DIO_HIGH){
			SET_BIT(GPIOA->ODR,Copy_u8Pin);
		}
		else if(u8Copy_u8Value==DIO_LOW){
			CLR_BIT(GPIOA->ODR,Copy_u8Pin);

		}
		break;
	case DIOB:
			if(u8Copy_u8Value==DIO_HIGH){
				SET_BIT(GPIOB->ODR,Copy_u8Pin);
			}
			else if(u8Copy_u8Value==DIO_LOW){
				CLR_BIT(GPIOB->ODR,Copy_u8Pin);

			}
			break;
	case DIOC:
			if(u8Copy_u8Value==DIO_HIGH){
				SET_BIT(GPIOC->ODR,Copy_u8Pin);
			}
			else if(u8Copy_u8Value==DIO_LOW){
				CLR_BIT(GPIOC->ODR,Copy_u8Pin);

			}
			break;


	}
}
u8   MDIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case DIOA:
		LOC_u8Result = GET_BIT( GPIOA->IDR , Copy_u8Pin );

		break;
	case DIOB:

		LOC_u8Result = GET_BIT( GPIOB->IDR, Copy_u8Pin );

		break;
	case DIOC:

		LOC_u8Result = GET_BIT( GPIOC->IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}
void MDIO_voidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	switch( Copy_u8Port ){

	case DIOA:

		if      ( Copy_u8Position == DIO_LOW  ) { GPIOA->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { GPIOA->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case DIOB:

		if      ( Copy_u8Position == DIO_LOW  ) { GPIOA->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { GPIOA->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case DIOC:

		if      ( Copy_u8Position == DIO_LOW  ) { GPIOA->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == DIO_HIGH ) { GPIOA->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	default :break;

	}

}
void MDIO_voidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	switch( Copy_u8Port ){

	case DIOA:

		if      ( Copy_u8Position == DIO_LOW  ){ GPIOA->ODR = (GPIOA->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ GPIOA->ODR = (GPIOA->ODR & 0x00FF ) | (     Copy_u8Value<<8 ) ; }

		break;
	case DIOB:

		if      ( Copy_u8Position == DIO_LOW  ){ GPIOB->ODR = (GPIOB->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ GPIOB->ODR = (GPIOB->ODR & 0x00FF ) | (     Copy_u8Value<<8 ) ; }

		break;
	case DIOC:

		if      ( Copy_u8Position == DIO_LOW  ){ GPIOC->ODR = (GPIOC->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == DIO_HIGH ){ GPIOC->ODR = (GPIOC->ODR & 0x00FF ) | (     Copy_u8Value )<<8 ; }

		break;
	default :break;

	}

}


