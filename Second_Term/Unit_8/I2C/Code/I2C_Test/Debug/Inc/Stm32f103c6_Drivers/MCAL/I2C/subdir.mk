################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.c 

OBJS += \
./Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.o 

C_DEPS += \
./Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Stm32f103c6_Drivers/MCAL/I2C/%.o Inc/Stm32f103c6_Drivers/MCAL/I2C/%.su: ../Inc/Stm32f103c6_Drivers/MCAL/I2C/%.c Inc/Stm32f103c6_Drivers/MCAL/I2C/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-strict-aliasing -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-I2C

clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-I2C:
	-$(RM) ./Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.d ./Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.o ./Inc/Stm32f103c6_Drivers/MCAL/I2C/I2C_Program.su

.PHONY: clean-Inc-2f-Stm32f103c6_Drivers-2f-MCAL-2f-I2C
