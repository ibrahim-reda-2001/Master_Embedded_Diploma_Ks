#include "RCC_private.h"
#include"RCC_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"



int main(){
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOB_RCC);
	MDIO_voidSetPinDirection(DIOA, PIN1, INPUT_FLOATING);
	MDIO_voidSetPinDirection(DIOA, PIN13, INPUT_FLOATING);
	MDIO_voidSetPinDirection(DIOB, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, PIN13, OUTPUT_SPEED_10MHZ_PP);
	while(1){
		if (MDIO_u8GetPinValue(DIOA, PIN1)==0){
			GPIOB->ODR^=(1<<PIN1);

		while(MDIO_u8GetPinValue(DIOA, PIN1)==0);
		}

	if (MDIO_u8GetPinValue(DIOA, PIN13)==1){
				GPIOB->ODR^=(1<<PIN13);
			}
for(int i =0;i<1000;i++);
		}


	return 0;
}
