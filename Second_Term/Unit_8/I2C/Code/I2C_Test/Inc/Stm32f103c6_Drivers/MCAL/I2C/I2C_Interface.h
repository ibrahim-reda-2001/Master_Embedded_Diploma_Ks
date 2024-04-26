/*
 * I2C_Interface.h
 *
 *  Created on: Apr 17, 2024
 *      Author: MAGIC
 */

#ifndef STM32F103C6_DRIVERS_MCAL_I2C_I2C_INTERFACE_H_
#define STM32F103C6_DRIVERS_MCAL_I2C_I2C_INTERFACE_H_
#include "I2C_Private.h"
#include "../DIO/DIO_interface.h"
#include "../RCC/RCC_interface.h"
//#include "BitField_I2C.h"


/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */
/*
 * =====================================================
 *                Generic Macros
 * =====================================================
 */


//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//         IVT
//_*_*_*_*_*_*_*_*_*_*_*_*_*

#define I2C1_EV_IRQ        31
#define I2C1_ER_IRQ        32
#define I2C2_EV_IRQ        33
#define I2C2_ER_IRQ        34

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//NVIC IRQ Enable/Disable  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*

#define I2C1_EV_IRQ_Enable     NVIC_ISER0_I2C|=(1<<I2C1_EV_IRQ)
#define I2C1_ER_IRQ_Enable	   NVIC_ISER1_I2C|=(1<<0)
#define I2C2_EV_IRQ_Enable     NVIC_ISER1_I2C|=(1<<1)
#define I2C2_ER_IRQ_Enable     NVIC_ISER1_I2C|=(1<<2)

#define I2C1_EV_IRQ_Disable     NVIC_ICER0_I2C|=(1<<I2C1_EV_IRQ)
#define I2C1_ER_IRQ_Disable	    NVIC_ICER1_I2C|=(1<<0)
#define I2C2_EV_IRQ_Disable     NVIC_ICER1_I2C|=(1<<1)
#define I2C2_ER_IRQ_Disable     NVIC_ICER1_I2C|=(1<<2)

//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       SPI Configuration
//_*_*_*_*_*_*_*_*_*_*_*_*_*
typedef struct {
	u16 Enable_Dual_ADD_ACK; //enable or disable
	u16 Primary_Slave_ADD;
	u16 Secondary_Slave_ADD;
	u32 Addressing_Slave_Mode; // 7 bits or 10 bits
							   //@ref I2C_Addressing slave

}S_Device_Address;

typedef enum {
	I2C_EV_Stop,
	I2C_ERROR_AF,
	I2C_ADDR_Matched,
	I2C_EV_DATA_REQ,// the APP layer should send data (I2C_SlaveSendData)
	I2C_EV_DATA_RECX // the APP layer should send data (I2C_SlaveReceiveData)
}SlaveState;
typedef struct{
	u32 I2C_Speed;                               // this parameters specific Clock set I2C Clock
									            //@REF I2C_SCLK
	u32 Stretch_Mode;                          //this parameter stretch Clock
									          //@ref I2C_StretchMode
	u32 I2C_Mode;                            //this select I2C or SMBus
								    	    //@ref I2C_Mode
	S_Device_Address I2C_Slave_Dvice_ADD;
	u32 I2C_ACK_Control ;                  //this parameter enable or disable ACK
										  //@ref I2C_ACK
	void (*P_Slave_Event_CallBack)(SlaveState state);

}I2C_InitTypeDef;


//======================================================
//_*_*_*_*_*_*_*_*_*_*_*_*_*
//       Reference  Macros
//_*_*_*_*_*_*_*_*_*_*_*_*_*

//@REF I2C_SCLK
// Standard Speed (up to 100 kHz)
//Fast Speed (up to 400 kHz)
//1-Program the peripheral input clock in I2C_CR2 register in order to generate correct timings
// Bits 5:0 FREQ[5:0]: Peripheral clock frequency =>I2C_CR2
//2-Configure the clock control registers //CCR =>I2C_CCR
//3-Configure the rise time register =>I2C_TRISE   ( incremented by 1)(Tpclk+1) Tpclk=>FREQ[5:0]
//4-enable peripheral =>I2C_CR1
//select standard mode(50% duty cycle)  or  fast mode (can modify duty cycle)
#define I2C_SCLK_SM_50K         (50000U)
#define I2C_SCLK_SM_100K         (100000U)

//@ref I2C_StretchMode
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//0: Clock stretching enabled
//1: Clock stretching disabled
#define I2C_Stretch_Mode_Enable     (u32)(0x00000000)
#define I2C_Stretch_Mode_Disable	I2C_CR1_NOSTRETCH
//@ref I2C_Mode
//Bit 1 SMBUS: SMBus mode
//0: I2C mode
//1: SMBus mode
#define I2C_Modde    (u32)(0x00000000)
#define SMBus_Mode   I2C_CR1_SMBUS
//@ref I2C_Addressing slave
//I2C=>OAR1 select 7 or 10 bit
#define I2C_Addressing_Slave_Mode_7Bit        (u32)(0x00000000)
#define I2C_Addressing_Slave_Mode_10Bit		  (1<<15)
//@ref I2C_ACK
//Bit 10 ACK: Acknowledge enable
//0: No acknowledge returned
//1: Acknowledge returned after a byte is received (matched address or data)
#define I2C_ACK_Disable       (u32)(0x00000000)
#define I2C_ACK_ENable        I2C_CR1_ACK

/*
 *
 * =================================================================
 *                       APIs OF I2C
 * ====================================================================
 *
 */
typedef enum{
	Without_Stop,
	With_Stop

}StopCondition;
typedef enum {
	WithoutRepeatStart,
	WithRepeatStart
}Repeated_Start;
typedef enum {
	Disable,
	Enable

}FunctionState;

typedef enum{
	RESET=0,
	SET=1
}FlagStatus;
typedef enum{
	I2C_FLAG_BUSY,
	EV5,//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6,//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	EV8,//EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register .
//	EV8_1,// TxE=1, shift register empty, data register empty, write Data1 in DR.
//	EV8_2,//EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	EV7,//EV7: RxNE=1 cleared by reading DR register.
	MASTER_BYTE_TRANSMITTER=((u32)0x00070080)
}StatusFlagCheck;

typedef enum{
	I2C_Direction_Transmiter,
	I2C_Direction_Reciver
}I2C_Direction;
void MCAL_I2C_Init(I2C_TypeDef* I2Cx,I2C_InitTypeDef* I2C_Struct );
void MCAL_I2C_DeInit(I2C_TypeDef* I2Cx);
void MCAL_I2C_Set_Pins(I2C_TypeDef* I2Cx);

//Master polling mechanism
void MCAL_I2C_Master_TX(I2C_TypeDef* I2Cx,u16 Device_Addr,u8* DataOut,u8 DataLength,StopCondition stop,Repeated_Start start );
void MCAL_I2C_Master_RX(I2C_TypeDef* I2Cx,u16 Device_Addr,u8* DataOut,u8 DataLength,StopCondition stop,Repeated_Start start );

//Slave interrupt mechanism

//Generic APIs

void MCAL_I2C_GenerateStart(I2C_TypeDef* I2Cx ,FunctionState NewState ,Repeated_Start start );

FlagStatus MCAL_I2C_GetFlagStatus(I2C_TypeDef* I2Cx,StatusFlagCheck flag);

void MCAL_I2C_SendAdd(I2C_TypeDef* I2Cx,u16 address, I2C_Direction direction);
//direction here mean write or read

void MCAL_I2C_Generate_Stop(I2C_TypeDef* I2Cx,FunctionState state);
void MCAL_I2C_Generate_ACK(I2C_TypeDef* I2Cx,FunctionState state);

/************************************************************ Slave ******************************************/
// using interrupt Mechanism
void MCAL_I2C_Slave_Send(I2C_TypeDef* I2Cx,u8 data);
u8 MCAL_I2C_Slave_Recive(I2C_TypeDef* I2Cx);







#endif /* STM32F103C6_DRIVERS_MCAL_I2C_I2C_INTERFACE_H_ */
