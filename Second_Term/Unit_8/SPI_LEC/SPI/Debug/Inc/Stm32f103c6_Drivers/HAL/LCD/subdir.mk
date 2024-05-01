################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.c 

OBJS += \
./Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.o 

C_DEPS += \
./Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Stm32f103c6_Drivers/HAL/LCD/%.o Inc/Stm32f103c6_Drivers/HAL/LCD/%.su: ../Inc/Stm32f103c6_Drivers/HAL/LCD/%.c Inc/Stm32f103c6_Drivers/HAL/LCD/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-Stm32f103c6_Drivers-2f-HAL-2f-LCD

clean-Inc-2f-Stm32f103c6_Drivers-2f-HAL-2f-LCD:
	-$(RM) ./Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.d ./Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.o ./Inc/Stm32f103c6_Drivers/HAL/LCD/LCD_program.su

.PHONY: clean-Inc-2f-Stm32f103c6_Drivers-2f-HAL-2f-LCD

