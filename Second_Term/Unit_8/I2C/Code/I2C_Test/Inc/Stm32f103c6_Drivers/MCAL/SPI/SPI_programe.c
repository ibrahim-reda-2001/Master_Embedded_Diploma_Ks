#include "SPI_private.h"
#include "SPI_interface.h"

#define null (void*)0

/*
 * =====================================================
 *                Generic Variables
 * =====================================================
 */
//array of global pointer store value  SPI_config
SPI_config* GL_SPI_Config[2]={null,null};
SPI_config GL_SPI_Config1;
SPI_config GL_SPI_Config2;
/*
 * =====================================================
 *                APIs
 * =====================================================
 */

/* =========================
 * @fn                  -MCAL_SPI_INIT
 * @brief               -Initialize SPI (SYNCH)
 * @param[in]           -SPIx : where x is 1,2,depend on device.........
 * @param[in]           - SPIConfig: all SPI configuration in SPI_config
 * @retval              -NONE
 * note                 -support SPI full DUPLEX master/slave only & NSS HW and SW
 */
void MCAL_SPI_Init(SPI_TypeDef* SPIx,SPI_config* SPIX_config ){
	//Safety for Register
	u32 tempreg_cr1=0;
	u32 tempreg_cr2=0;
	if (SPIx==SPI1){
		GL_SPI_Config1=*SPIX_config;
		GL_SPI_Config[SPI1_index]=&GL_SPI_Config1;
	}
	else if(SPIx==SPI2){
		GL_SPI_Config2=*SPIX_config;
		GL_SPI_Config[SPI2_index]=&GL_SPI_Config2;

	}
	//enable SPI Bit 6 SPE: SPI enable
	tempreg_cr1|=(0X1U<<6);
	//select SPI mode if(master or slave )
	tempreg_cr1|=SPIX_config->Device_Mode;
	//SPI communication_Mode (full DUPLEX or receiver or ..........)
	tempreg_cr1|=SPIX_config->Communicatio_Mode;
	//select frame format if(MSB or LSB )
	tempreg_cr1|=SPIX_config->Frame_Format;
	//select SPI Data size if(8 or 16 Bits )
	tempreg_cr1|=SPIX_config->Data_Size;
	//select SPI clock polarity(0,1 )
	tempreg_cr1|=SPIX_config->Clock_Polarity;
	//select SPI clock phase(1,0)
	tempreg_cr1|=SPIX_config->Clock_Phase;
	/**************************** NSS  ************************************/
	if (SPIX_config->NSS==SPI_NSS_Hardware_Master_SS_output_enable){
		tempreg_cr2|=SPIX_config->NSS;//cr2
	}
	else if(SPIX_config->NSS==SPI_NSS_Hardware_Master_SS_output_disable){
		tempreg_cr2|=SPIX_config->NSS;//cr2
	}
	else {
		tempreg_cr1|=SPIX_config->NSS;//cr1
	}
	//select SPI baud rate(2,4,8,16,32,64,128,256,512 )
	tempreg_cr1|=SPIX_config->SPI_BaudRatePrescaler;

	/******************************** Interrupt ****************************/
	//cr2
	if(SPIX_config->IRQ_Enable!= SPI_IRQ_Enable_None){
		tempreg_cr2|=SPIX_config->IRQ_Enable;

		if(SPIx==SPI1){
			SPI1_IRQ_Enable;
		}
		else if(SPIx==SPI2){
			SPI2_IRQ_Enable;
		}
	}
	SPIx->CR1=tempreg_cr1;
	SPIx->CR2=tempreg_cr2;

}
/* =========================
 * @fn                  -MCAL_SPI_Send_Data
 * @brief               -send data by spi
 * @param[in]           -SPIx and Buffer and polling option
 * @param[in]           - SPIx
 * @retval              -NONE
 * note                 -none
 */
void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx,u16* SPI_Buffer ,Polling_spi_mechnism PollingEn){
	if(PollingEn==SPI_polling_enable){
		while(!(SPIx->SR&SPI_SR_TXE));
	}
	SPIx->DR=*SPI_Buffer;

}
/* =========================
 * @fn                  -MCAL_SPI_receive_Data
 * @brief               -receive data by SPI
 * @param[in]            -SPIx and Buffer and polling option
 * @param[in]           - SPIx
 * @retval              -NONE
 * note                 -none
 */
void MCAL_SPI_Receive_Data(SPI_TypeDef* SPIx,u16* SPI_Buffer ,Polling_spi_mechnism PollingEn){
	SPIx->DR=25;
	if(PollingEn==SPI_polling_enable){
		while(!(SPIx->SR&SPI_SR_RXNE));
	}
	*SPI_Buffer=SPIx->DR;

}
/* =========================
 * @fn                  -MCAL_SPI_receive_send_Data
 * @brief               -receive and send data by SPI
 * @param[in]           -SPIx and Buffer and polling option
 * @param[in]           - SPIx
 * @retval              -NONE
 * note                 -none
 */

void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx, u16 * SPI_Buffer ,Polling_spi_mechnism PollingEn){
	if(PollingEn==SPI_polling_enable){
		while(!(SPIx->SR&SPI_SR_TXE));
	}
	SPIx->DR=*(SPI_Buffer) & 0xFF;
	if(PollingEn==SPI_polling_enable){
		while(!(SPIx->SR&SPI_SR_RXNE));
	}

	*(SPI_Buffer)=SPIx->DR;

}


/********************************** SPI_Pins_Init ******************************/
void MCAL_SPI_Set_Pins(SPI_TypeDef* SPIx){

	//you should choice from SPI_congif file which SPI work
if (SPIx==SPI1){
	//PA4:SPI_NSS
	//PA5:SPI_SCK
	//PA6:SPI_MISO
	//PA7:SPI_MOSI
	if(GL_SPI_Config[SPI1_index]->Device_Mode==SPI_Device_Mode_Master){    //master
		//PA4:SPI_NSS
		switch(GL_SPI_Config[SPI1_index]->NSS){
		case SPI_NSS_Hardware_Master_SS_output_disable:
			MDIO_voidSetPinDirection(DIOA, PIN4, INPUT_FLOATING);                        break;
		case SPI_NSS_Hardware_Master_SS_output_enable:
			MDIO_voidSetPinDirection(DIOA, PIN4, OUTPUT_SPEED_10MHZ_AFPP);                        break;
		}
		//PA5:SPI_SCK
		MDIO_voidSetPinDirection(DIOA, PIN5, OUTPUT_SPEED_2MHZ_AFPP);
		//PA6:SPI_MISO
		//Full duplex / master Input floating / Input pull-u
		MDIO_voidSetPinDirection(DIOA, PIN6, INPUT_FLOATING);
		//PA7:SPI_MOSI
		//Full duplex / master Alternate function push-pull
		MDIO_voidSetPinDirection(DIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP);

	}
	else if (GL_SPI_Config[SPI1_index]->Device_Mode==SPI_Device_Mode_Slave){    //slave
		if(GL_SPI_Config[SPI1_index]->NSS==SPI_NSS_Hardware_Slave){
			MDIO_voidSetPinDirection(DIOA, PIN4, INPUT_FLOATING);
		}
		//PA5:SPI_SCK
		//Slave Input floating
		MDIO_voidSetPinDirection(DIOA, PIN5, INPUT_FLOATING);
		//PA6:SPI_MISO
		//Full duplex / slave (point to point) Alternate function push-pull
		MDIO_voidSetPinDirection(DIOA, PIN6, OUTPUT_SPEED_10MHZ_AFPP);
		//PA7:SPI_MOSI
		//Full duplex / slave Input floating / Input pull-up
		MDIO_voidSetPinDirection(DIOA, PIN7, INPUT_FLOATING);
	}
}

	else if (SPIx==SPI2){
	//NOT PROVIDED IN stm32f103c6 it is in stm32f103c8 but it is same by copy and paste
	//PA12:SPI2_NSS
	//PA13:SPI2_SCK
	//PA14:SPI2_MISO
	//PA15:SPI2_MOSI
	}
}

/*
 * =====================================================
 *                IRQ
 * =====================================================
 */

void SPI1_IRQHandler(){
	struct 	SPI_IRQ_Src irq_src;
	irq_src.TXE=Get_Bit(SPI1->SR,1);
	irq_src.RXNE=Get_Bit(SPI1->SR,0);
	irq_src.ERRI=Get_Bit(SPI1->SR,4);

	GL_SPI_Config[SPI1_index]->Ptr_IRQ_CallBack(irq_src);
}
void SPI2_IRQHandler(){
	struct 	SPI_IRQ_Src irq_src;
	irq_src.TXE=Get_Bit(SPI2->SR,1);
		irq_src.RXNE=Get_Bit(SPI2->SR,0);
		irq_src.ERRI=Get_Bit(SPI2->SR,4);
		GL_SPI_Config[SPI2_index]->Ptr_IRQ_CallBack(irq_src);
}


