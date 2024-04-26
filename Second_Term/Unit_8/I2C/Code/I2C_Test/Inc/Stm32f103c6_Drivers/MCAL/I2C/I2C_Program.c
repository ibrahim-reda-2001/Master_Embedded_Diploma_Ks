#include "I2C_Interface.h"

/*
 * =====================================================
 *                Generic Variables
 * =====================================================
 */
I2C_InitTypeDef GL_I2C_Config[2]={0,0};


/*
 * =====================================================
 *                Generic Macros
 * =====================================================
 */
#define I2C1_Index          1
#define I2C2_Index          2
#define MASTER_BYTE_TRANSMITTER      ((u32)0x00070080) //this to check master ,transmitter , busy and transmitter buffer is empty


/*
 * =====================================================
 *                APIs
 * =====================================================
 */
void MCAL_I2C_Init(I2C_TypeDef* I2Cx,I2C_InitTypeDef* I2C_Struct ){
	volatile u32 tempreg=0,freqrange=0,Fpclk=0,result=0;
	//Enable RCC for I2C
	if(I2Cx==I2C1_Reg){
		GL_I2C_Config[I2C1_Index]=*I2C_Struct;
//		RCC_voidEnablePeripheralClock(APB1_BUS,I2C1_RCC);
	}
	else if(I2Cx==I2C2_Reg){
		GL_I2C_Config[I2C2_Index]=*I2C_Struct;
		RCC_voidEnablePeripheralClock(APB1_BUS,I2C2_RCC);
	}

	if(I2C_Struct->I2C_Mode==I2C_Modde){
		/****************************** INit Timing *****************************************/
		//1-Program the peripheral input clock in I2C_CR2 register in order to generate correct timings
		// Bits 5:0 FREQ[5:0]: Peripheral clock frequency =>I2C_CR2
		tempreg|=I2Cx->I2C_CR2;
		//clear FREQ range
		tempreg &=~(I2C_CR2_FREQ_Msk);
		//Get Fpclk
		Fpclk=RCC_u32GetPClk1Freq();
		//set frequency bit
		freqrange=Fpclk/1000000;
		tempreg|=freqrange;
		I2Cx->I2C_CR2|=tempreg;
		//configure clock control Register(CCR)
		tempreg=0;
		I2Cx->I2C_CR1&=~(I2C_CR1_PE);
		if(I2C_Struct->I2C_Speed==I2C_SCLK_SM_50K||I2C_Struct->I2C_Speed==I2C_SCLK_SM_100K){
			//calculate CCR
			result=(u16)((Fpclk)/(I2C_Struct->I2C_Speed<<1));
			tempreg|=result;
			I2Cx->I2C_CCR|=tempreg;
			tempreg=0;
			/*********** Configure Rise time configuration **************/
			I2Cx->I2C_TRISE|=freqrange+1;

		}
		else{
			//fast mode not supported yet
		}

		/********************** CR1 COnfig *****************/


		tempreg=I2Cx->I2C_CR1;
		tempreg|=(u16)(I2C_Struct->I2C_ACK_Control | I2C_Struct->Stretch_Mode|I2C_Struct->I2C_Mode);
		I2Cx->I2C_CR1=tempreg;

		/**************************** Slavr ADD configure OAR1 & OAR2 ***************/

		tempreg=0;
		if(I2C_Struct->I2C_Slave_Dvice_ADD.Enable_Dual_ADD_ACK==1){
			tempreg=I2C_OAR2_ENDUAL;
			//secondary address
			tempreg|=(I2C_Struct->I2C_Slave_Dvice_ADD.Secondary_Slave_ADD<<I2C_OAR2_ADD2_Pos);
			tempreg=I2Cx->I2C_OAR2;
		}
		tempreg=0;
		tempreg|=(I2C_Struct->I2C_Slave_Dvice_ADD.Primary_Slave_ADD<<1);
		tempreg|=(I2C_Struct->I2C_Slave_Dvice_ADD.Addressing_Slave_Mode<<15);
		I2Cx->I2C_OAR1=tempreg;


	}
	else {
		//SMBus not supported yet
	}
	//interrupt mode  (slave mode) by check callback function != null
	if(I2C_Struct->P_Slave_Event_CallBack!=NULL_POINTER)//that enable IRQ state enable
	{

		//Enable IRQ
		I2Cx->I2C_CR2|=(I2C_CR2_ITBUFEN);
		I2Cx->I2C_CR2|=(I2C_CR2_ITERREN);
		I2Cx->I2C_CR2|=(I2C_CR2_ITEVTEN);
		if(I2Cx==I2C1_Reg){
			I2C1_EV_IRQ_Enable;
			I2C1_ER_IRQ_Enable;
		}
		else{
			I2C2_EV_IRQ_Enable;
			I2C2_ER_IRQ_Enable;
		}

	}

	//enable selected I2C Peripheral
	I2Cx->I2C_CR1|=(I2C_CR1_PE);

}
void MCAL_I2C_DeInit(I2C_TypeDef* I2Cx){
	if(I2Cx==I2C1_Reg){

		RCC_voidDisablePeripheralClock(APB1_BUS,I2C1_RCC);
		I2C1_EV_IRQ_Disable;
		I2C1_ER_IRQ_Disable;
	}
	else if(I2Cx==I2C2_Reg){
		RCC_voidDisablePeripheralClock(APB1_BUS,I2C2_RCC);
		I2C2_EV_IRQ_Disable;
		I2C2_ER_IRQ_Disable;
	}
}
void MCAL_I2C_Set_Pins(I2C_TypeDef* I2Cx){
	if(I2Cx==I2C1_Reg){
		// PB6   :I2C clock
		//  PB7   : I2C Data I/O
		MDIO_voidSetPinDirection(DIOB, PIN6, OUTPUT_SPEED_10MHZ_AFOD);
		MDIO_voidSetPinDirection(DIOB, PIN7, OUTPUT_SPEED_10MHZ_AFOD);


	}
	else if(I2Cx==I2C2_Reg){
		//  PB10   :I2C clock
		//  PB11   : I2C Data I/O
		MDIO_voidSetPinDirection(DIOB, PIN10, OUTPUT_SPEED_10MHZ_AFOD);
		MDIO_voidSetPinDirection(DIOB, PIN11, OUTPUT_SPEED_10MHZ_AFOD);

	}
}
void MCAL_I2C_GenerateStart(I2C_TypeDef* I2Cx ,FunctionState NewState ,Repeated_Start start ){

	if (start==WithoutRepeatStart){
		//check in bus in I2C_SR2
		//		Bit 1 BUSY: Bus busy
		//		0: No communication on the bus
		//		1: Communication ongoing on the bus
		while(MCAL_I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY));

	}
	if(NewState==Enable){
		I2Cx->I2C_CR1|=I2C_CR1_START;
	}
	else if(NewState==Disable){
		I2Cx->I2C_CR1&=~I2C_CR1_START;

	}

}
void MCAL_I2C_SendAdd(I2C_TypeDef* I2Cx,u16 address, I2C_Direction direction){
	//	default 7 bit address
	address<<=1;
	if(direction!=I2C_Direction_Transmiter){
		address|=(1<<0);
		//this to read
	}
	else{
		address&=~(1<<0);
		//this to write
	}
	I2Cx->I2C_DR=address;

}
void MCAL_I2C_Generate_Stop(I2C_TypeDef* I2Cx,FunctionState state){
	if(state!=Disable){
		I2Cx->I2C_CR1|=I2C_CR1_STOP;
	}
	else{
		I2Cx->I2C_CR1&=~(I2C_CR1_STOP);

	}
}
void MCAL_I2C_Generate_ACK(I2C_TypeDef* I2Cx,FunctionState state){
	if(state!=Disable){
		I2Cx->I2C_CR1|=I2C_CR1_ACK;
	}
	else{
		I2Cx->I2C_CR1&=~(I2C_CR1_ACK);

	}
}
FlagStatus MCAL_I2C_GetFlagStatus(I2C_TypeDef* I2Cx,StatusFlagCheck flag){
	volatile u32 dummy_data=0;//this used to read data from any Register
	volatile u32 flag1;
	volatile u32 flag2;
	FlagStatus BitStaus=RESET;
	switch (flag){
	case I2C_FLAG_BUSY:BitStaus=I2Cx->I2C_SR2&I2C_SR2_BUSY;   break;
	case EV5:BitStaus=I2Cx->I2C_SR1&I2C_SR1_SB; break;
	case EV6: BitStaus=I2Cx->I2C_SR1&I2C_SR1_ADDR;	dummy_data=I2Cx->I2C_SR2; break;//to clear flag  break;
	case MASTER_BYTE_TRANSMITTER:flag1=I2Cx->I2C_SR1;flag2=I2Cx->I2C_SR2;flag2=flag2<<16;BitStaus=(flag1|flag2)&&flag;break;
	case EV8: BitStaus=I2Cx->I2C_SR1&I2C_SR1_TXE;break;
	case EV7:BitStaus=I2Cx->I2C_SR1&I2C_SR1_RXNE;break;
	}
	return BitStaus;
}
void MCAL_I2C_Master_TX(I2C_TypeDef* I2Cx,u16 Device_Addr,u8* DataOut,u8 DataLength,StopCondition stop,Repeated_Start start ){
	//1-send start bit in I2C CR1 to generate start condition
	//to do ad timeout for void MCAL_I2C_GenerateStart configure timer with specefic duration when time end timer fire interrupt
	//timer interrupt service routine rise a flag
	//and in while checking for flag
	MCAL_I2C_GenerateStart(I2Cx,Enable,start);
	//2-EV5 is Bit 0 SB: Start bit (Master mode) then write on data register address
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV5)));
	//3-Send Address
	MCAL_I2C_SendAdd(I2Cx,Device_Addr,I2C_Direction_Transmiter);
	//4-EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV6)));
	//	4-check master , busy   ,transmitter and TXE empty
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, MASTER_BYTE_TRANSMITTER)));
	//5-write data
	for(int i=0;i<DataLength;i++){
		//write on data register and wait for ACK EV8
		I2Cx->I2C_DR=DataOut[i];
		//		EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register .
		while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV8)));

	}

	//EV8_2
	//while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV8_2)));
if(stop== With_Stop){
	MCAL_I2C_Generate_Stop(I2Cx, Enable);
}

}
void MCAL_I2C_Master_RX(I2C_TypeDef* I2Cx,u16 Device_Addr,u8* DataOut,u8 DataLength,StopCondition stop,Repeated_Start start ){
	//send start bit
	u8 index= I2Cx==I2C1_Reg?I2C1_Index:I2C2_Index;
	MCAL_I2C_GenerateStart(I2Cx,Enable,start);
	//2-EV5 is Bit 0 SB: Start bit (Master mode) then write on data register address
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV5)));
	//3-Send Address
	MCAL_I2C_SendAdd(I2Cx,Device_Addr,I2C_Direction_Reciver);
	//4-EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV6)));
	MCAL_I2C_Generate_ACK(I2Cx, Enable);

	if(DataLength){
		for(int i=DataLength;i>1;i--){

			while(!(MCAL_I2C_GetFlagStatus(I2Cx, EV7)));
			*DataOut=I2Cx->I2C_DR;
			DataOut++;
		}
		MCAL_I2C_Generate_ACK(I2Cx, Disable);

	}
	if(stop==With_Stop)
		MCAL_I2C_Generate_Stop(I2Cx, Enable);

	if(GL_I2C_Config[index].I2C_ACK_Control==I2C_ACK_ENable){
		MCAL_I2C_Generate_ACK(I2Cx, Enable);

	}

}

/************************************************************ Slave ******************************************/
// using interrupt Mechanism
void MCAL_I2C_Slave_Send(I2C_TypeDef* I2Cx,u8 data){
I2Cx->I2C_DR=data;
}
u8 MCAL_I2C_Slave_Recive(I2C_TypeDef* I2Cx){
return (u8)I2Cx->I2C_DR;
}
void I2C1_EV_IRQHandler(){

}
void I2C1_ER_IRQHandler(void){

}
