################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/DIO_programe.c \
../Inc/KPD_program.c \
../Inc/LCD_program.c \
../Inc/RCC_programe.c \
../Inc/Wait_ms.c 

OBJS += \
./Inc/DIO_programe.o \
./Inc/KPD_program.o \
./Inc/LCD_program.o \
./Inc/RCC_programe.o \
./Inc/Wait_ms.o 

C_DEPS += \
./Inc/DIO_programe.d \
./Inc/KPD_program.d \
./Inc/LCD_program.d \
./Inc/RCC_programe.d \
./Inc/Wait_ms.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/DIO_programe.d ./Inc/DIO_programe.o ./Inc/DIO_programe.su ./Inc/KPD_program.d ./Inc/KPD_program.o ./Inc/KPD_program.su ./Inc/LCD_program.d ./Inc/LCD_program.o ./Inc/LCD_program.su ./Inc/RCC_programe.d ./Inc/RCC_programe.o ./Inc/RCC_programe.su ./Inc/Wait_ms.d ./Inc/Wait_ms.o ./Inc/Wait_ms.su

.PHONY: clean-Inc

