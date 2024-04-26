#include "../../LIP/Wait_ms.h"
#include "../../LIP/STD_TYPES.h"
#include "../../LIP/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"
//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 1
const u8 APB1or2_Prescaler[8]={0,0,0,0,1,2,3,4};
//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
//32 not found
const u8 AHB_Prescaler[16]={0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};
//Bits 21:18 PLLMUL: PLL multiplication factor
//These bits are written by software to define the PLL multiplication factor. These bits can be
//written only when PLL is disabled.
//Caution: The PLL output frequency must not exceed 72 MHz.
//0000: PLL input clock x 2
//0001: PLL input clock x 3
//0010: PLL input clock x 4
//0011: PLL input clock x 5
//0100: PLL input clock x 6
//0101: PLL input clock x 7
//0110: PLL input clock x 8
//0111: PLL input clock x 9
//1000: PLL input clock x 10
//1001: PLL input clock x 11
//1010: PLL input clock x 12
//1011: PLL input clock x 13
//1100: PLL input clock x 14
//1101: PLL input clock x 15
//1110: PLL input clock x 16
//1111: PLL input clock x 16
const u8 Pll_MUL[16]={2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16};

void RCC_voidInitSysClock(void)
{
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR = 0x00010000; /* Enable HSE with no bypass */
	RCC_CFGR = 0x00000001;

#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR = 0x00050000; /* Enable HSE with bypass */
	RCC_CFGR = 0x00000001;

#elif RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR = 0x00000081; /* Enable HSI + Trimming = 0 */
	RCC_CFGR = 0x00000000;

#elif RCC_CLOCK_TYPE == RCC_PLL
#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	RCC_CFGR |= (0b10 << 0);
	RCC_CFGR |= (0b0111 << 18);
	// RCC_CFGR|=(0b100<<8);
	// RCC_CFGR|=(0b101<<11);
	RCC_CR |= (1 << 24);

#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2

#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE

#endif

#else
#error("You chosed Wrong Clock type")
#endif
}

//==============================================================================================================

void RCC_voidEnablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){



	if (Copy_u8BusId <= 31)
	{
		switch( Copy_u8BusId ){

		case AHB_BUS  : SET_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
		case APB1_BUS :	SET_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
		case APB2_BUS : SET_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;
		//default       : /* Return Error */

		}
	}

	else
	{
		/* Return Error*/
	}


}

//==============================================================================================================
void RCC_voidDisablePeripheralClock( u8 Copy_u8BusId , u8 Copy_u8PeripheralId ){

	switch( Copy_u8BusId ){

	case AHB_BUS  : CLR_BIT( RCC_AHBENR  , Copy_u8PeripheralId ); break;
	case APB1_BUS :	CLR_BIT( RCC_APB1ENR , Copy_u8PeripheralId ); break;
	case APB2_BUS : CLR_BIT( RCC_APB2ENR , Copy_u8PeripheralId ); break;

	}
}
//==============================================================================================================
u32  RCC_u32GetSysClkFreq( void ){
u32 j=0;
	//	Bits 3:2 SWS: System clock switch status
	//	Set and cleared by hardware to indicate which clock source is used as system clock.
	//	00: HSI oscillator used as system clock
	//	01: HSE oscillator used as system clock
	//	10: PLL used as system clock
	//	11: not applicable
	switch((RCC_CFGR>>2)&0b11){
	case 0:
		return j=8000000;break;
	case 1:return j=16000000;break;
	case 2:
		return  j=(4000000*Pll_MUL[(RCC_CFGR>>18)&0b1111]);
		break;
	}
	return j;
}
//==============================================================================================================
u32  RCC_u32GetHClkFreq( void ){
	//	Bits 7:4 HPRE: AHB prescaler
	return (RCC_u32GetSysClkFreq()>>AHB_Prescaler[(RCC_CFGR>>4)&0b1111]);
}
//==============================================================================================================
u32  RCC_u32GetPClk1Freq( void ){
	//RCC_u8GetHClkFreq -> AHB clock
	//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	return (RCC_u32GetHClkFreq()>>APB1or2_Prescaler[(RCC_CFGR>>8)&0b111]);//shift right mean divide
}
//==============================================================================================================
u32  RCC_u32GetPClk2Freq( void ){
	//shift right mean divide
	//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	return (RCC_u32GetHClkFreq()>>APB1or2_Prescaler[(RCC_CFGR>>11)&0b111]);

}
//==============================================================================================================
