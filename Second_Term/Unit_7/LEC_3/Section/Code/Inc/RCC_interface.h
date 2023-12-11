/*
 * RCC_interface.h
 *
 *  Created on: ٠٢‏/١٠‏/٢٠٢٣
 *      Author: MAGIC
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#define ENABLE_PERIPHERAL     1
#define DISABLE_PERIPHERAL    0
#define RESET_PERIPHERAL      2
/*********************************************/
#define RCC_HSI									1
#define RCC_HSE_CRYSTAL                         2
#define RCC_PLL                         		3
#define RCC_HSE_RC        						4
#define RCC_PLL_IN_HSI_DIV_2                    5
#define RCC_PLL_IN_HSE_DIV_2        			6
#define RCC_PLL_IN_HSE                  		7
/*********************************************/
#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110
/*********************************************/

#define DISABLE_CLOCK_SECURITY_SYSTEM              0
#define ENABLE_CLOCK_SECURITY_SYSTEM               1
/******************AHB***************************/
#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10
/*******************APB2**************************/
#define    AFIO_RCC         0
#define    DIOA_RCC         2
#define    DIOB_RCC         3
#define    DIOC_RCC         4
#define    DIOD_RCC         5
#define    DIOE_RCC         6
#define    DIOF_RCC         7
#define    DIOG_RCC         8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21
/****************ABP1*****************************/
#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29
/*********************************************/
#define    AHB_BUS       0
#define    APB1_BUS      1
#define    APB2_BUS      2

//==============================================================================================================
void RCC_voidInitSysClock( void );

void RCC_voidEnablePeripheralClock  ( u8 Copy_u8BusId  , u8 Copy_u8PeripheralId );
void RCC_voidDisablePeripheralClock ( u8 Copy_u8BusId  , u8 Copy_u8PeripheralId );
#endif /* RCC_INTERFACE_H_ */
