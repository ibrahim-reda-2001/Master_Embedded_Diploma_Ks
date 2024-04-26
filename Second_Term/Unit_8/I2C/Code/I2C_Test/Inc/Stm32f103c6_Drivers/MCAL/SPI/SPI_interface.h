/*
 * SPI_interface.h
 *
 *  Created on: Mar 5, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_SPI_SPI_INTERFACE_H_
#define STM32F103C6_DRIVERS_MCAL_SPI_SPI_INTERFACE_H_
#include "SPI_private.h"
#include "SPI_config.h"
#include "../DIO/DIO_interface.h"


/*
 * =====================================================
 *                Generic Macros
 * =====================================================
 */

#define SPI1_index     				 0
#define SPI2_index      			 1
#define SPI_SR_TXE      			 ((u8)(0x02)) //it is mask value
#define SPI_SR_RXNE     			 ((u8)(0x01))//it is mask value
#define Get_Bit(REG,BIT) 			 ((REG&(1<<BIT))>>BIT)

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//         IVT
//_*_*_*_*_*_*_*_*_*_*_*_*_*
#define    SPI1_IRQ      (u16 )37
#define    SPI2_IRQ      (u16 )38


//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//NVIC IRQ Enable/Disable  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*
#define SPI1_IRQ_Enable  NVIC_ISER1_SPI|=(1<<(SPI1_IRQ-32))//37-32=5
#define SPI2_IRQ_Enable  NVIC_ISER1_SPI|=(1<<(SPI2_IRQ-32))//38-32=6

#define SPI1_IRQ_Disable  NVIC_ICER1_SPI|=(1<<(SPI1_IRQ-32))//37-32=5
#define SPI2_IRQ_Disable  NVIC_ICER1_SPI|=(1<<(SPI2_IRQ-32))//38-32=6

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       SPI Configuration
//_*_*_*_*_*_*_*_*_*_*_*_*_*
struct 	SPI_IRQ_Src{
	u8 TXE:1; //Transmitter buffer is empty
	u8 RXNE:1; //Receiver buffer not empty
	u8 ERRI:1;//Erorr interupt
	u8 reserved:5;
};


typedef struct{
u16  Device_Mode;										//Specified the SPI Operation mode
														//@ref SPI_Device_Mode
u16  Communicatio_Mode;                           		//Specified the Communication mode
														//@ref SPI_Communication_Mode
u16  Frame_Format;                                        //Specified the SPI Frame format
														//@ref SPI_Frame_Format
u16  Data_Size;                                          //Specified the SPI Data_Size
										  				//@ref SPI_Data_Size
u16  Clock_Polarity;                                      //Specified the Clock_Polarity
														//@ref SPI_Clock_Polarity
u16  Clock_Phase;                                         //Specified the SPI Clock_Phase
														//@ref SPI_Clock_Phase
u16  NSS;                                                //specified if NSS work Software Or Hardware can managed it
														//if it Hardware may be input or output
														//in input case(Hardware) it only detect if any master in bus
														//in output case(HardWare) if no another master in bus it generate 0 to make connection to slave if there is another master  and it detedct
														//zero in bus this master convert to slave
														//Software may be 1 or zero
														//@ref 	SPI_Clock_NSS
u16  SPI_BaudRatePrescaler;                              //specified SPI BaudRate
                                                        //@ref BaudRate
u16  IRQ_Enable;											//specified which interrupt is enable
														//@ref SPI_IRQ
void(*Ptr_IRQ_CallBack)(struct 	SPI_IRQ_Src irq_src) ;								//this pointer to function call when there interrupt
//this callback function take structure and return void structure pass by value cause it is small size only one byte
}SPI_config;

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       Reference  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*

//@ref SPI_Device_Mode
//CR1
#define SPI_Device_Mode_Slave         (0X00000000U)
#define SPI_Device_Mode_Master        (0X1U<<2)// CR1:Bit 2 MSTR: Master selection  1: Master configuration
/***************************************************************************************************************************/
//@ref SPI_Communication_Mode
//CR1
#define SPI_Direction_2_Lines_Full_Duplex		(0X00000000U)// Bit 15 BIDIMODE  0: 2-line unidirectional data mode selected
#define SPI_Direction_2_Lines_RXONLY			(1<<10)// Bit 15 BIDIMODE & Bit 10 RXONLY => 1: Output disabled (Receive-only mode)
#define SPI_Direction_1_Lines_Receive_only      (1<<15)//Bit 15 BIDIMODE  & Bit 14 BIDIOE: O=> 1: 1-line bidirectional data mode selected 0: Output disabled (receive-only mode)
#define SPI_Direction_1_Lines_Transmit_only     ((0x1U<<15) | (0x1U<<14))//Bit 15 BIDIMODE  & Bit 14 BIDIOE1: 1-line bidirectional data mode selected 	1: Output enabled (transmit-only mode)
/***************************************************************************************************************************/
//@ref SPI_Frame_Format
//CR1 #define SPI_Frame_Format_MSB
#define SPI_Frame_Format_MSB                    (0X00000000U)//0: MSB transmitted first
#define SPI_Frame_Format_LSB                    (0x1U<<7)//1: LSB transmitted first
/***************************************************************************************************************************/
//@ref SPI_Data_Size
//CR1 Bit 11 DFF: Data frame format
#define SPI_DataSize_8Bit     (0X00000000)//0: 8-bit data frame format is selected for transmission/reception
#define SPI_DataSize_16Bit    (0x1U<<11)//1: 16-bit data frame format is selected for transmission/reception
/***************************************************************************************************************************/
//@ref SPI_Clock_Polarity
//CR1
#define SPI_Clock_Polarity_LOW_idle      (0X00000000U)
#define SPI_Clock_Polarity_HIGH_idle      (0x1U<<1)
/***************************************************************************************************************************/
//@ref SPI_Clock_Phase
//CR1
#define  SPI_Clock_Phase_1EDGE_First_Data_Captur_Edge   (0X00000000U)//this sampling in first edge
#define  SPI_Clock_Phase_2EDGE_First_Data_Captur_Edge    (0x1U<<0)     //this sampling in second edge
//@ref 	SPI_Clock_NSS
//CR1 & CR2
//=========================== Hardware  ===========================
//Bit 9 SSM: Software slave management => CR1
//Bit 2 SSOE: SS output enable =>CR2
#define SPI_NSS_Hardware_Slave                              (0X00000000U)//CR1
#define SPI_NSS_Hardware_Master_SS_output_enable            (0x1U<<2)
#define SPI_NSS_Hardware_Master_SS_output_disable           (0X00000000U)
//=========================== Hardware  ===========================
//Bit 9 SSM: Software slave management
//Bit 8 SSI: Internal slave select
#define SPI_NSS_SoftWare_Master_or_Slave_Set          ((1<<9)|(1<<8))
#define SPI_NSS_SoftWare_Master_or_Slave_ReSet        (1<<9)
#define SPI_NSS_SoftWare_Disable                      (0X00000000U)
/***************************************************************************************************************************/
//@ref BaudRate
//CR1 Bits 5:3 BR[2:0]: Baud rate control
#define SPI_BaudRatePrescaler_2				    (0X00000000)
#define SPI_BaudRatePrescaler_4                 (0b001U<<3)
#define SPI_BaudRatePrescaler_8                 (0b010U<<3)
#define SPI_BaudRatePrescaler_16                (0b011U<<3)
#define SPI_BaudRatePrescaler_32                (0b100U<<3)
#define SPI_BaudRatePrescaler_64				(0b101U<<3)
#define SPI_BaudRatePrescaler_128				(0b110U<<3)
#define SPI_BaudRatePrescaler_256				(0b111U<<3)
/***************************************************************************************************************************/
//@ref SPI_IRQ
//CR2
#define SPI_IRQ_Enable_None            (0X00000000)
#define SPI_IRQ_Enable_TXEIE		   (1<<7)//1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
#define SPI_IRQ_Enable_RXNEIE          (1<<6)//1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is
#define SPI_IRQ_Enable_ERRIE           (1<<5)//1: Error interrupt is enabled

/*
 *
 * =================================================================
 *                       APIs OF SPI
 * ====================================================================
 *
 */
typedef enum {
	SPI_polling_enable,
	SPI_polling_disable
}Polling_spi_mechnism;

void MCAL_SPI_Init(SPI_TypeDef* SPIx,SPI_config* SPIX_config );
void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx,u16 * SPI_Buffer ,Polling_spi_mechnism PollingEn);
void MCAL_SPI_Receive_Data(SPI_TypeDef* SPIx,u16 * SPI_Buffer ,Polling_spi_mechnism PollingEn);
void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx, u16 * SPI_Buffer ,Polling_spi_mechnism PollingEn);
void MCAL_SPI_Set_Pins(SPI_TypeDef* SPIx);








#endif /* STM32F103C6_DRIVERS_MCAL_SPI_SPI_INTERFACE_H_ */
