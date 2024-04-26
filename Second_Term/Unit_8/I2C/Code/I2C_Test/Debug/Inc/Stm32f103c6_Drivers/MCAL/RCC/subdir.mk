################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.c 

OBJS += \
./Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.o 

C_DEPS += \
./Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Stm32f103c6_Drivers/MCAL/RCC/%.o Inc/Stm32f103c6_Drivers/MCAL/RCC/%.su: ../Inc/Stm32f103c6_Drivers/MCAL/RCC/%.c Inc/Stm32f103c6_Drivers/MCAL/RCC/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-RCC

clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-RCC:
	-$(RM) ./Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.d ./Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.o ./Inc/Stm32f103c6_Drivers/MCAL/RCC/RCC_programe.su

.PHONY: clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-RCC

