################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Inc/Stm32f103c6_Drivers/MCAL/Timer_2-5/subdir.mk
-include Inc/Stm32f103c6_Drivers/MCAL/RCC/subdir.mk
-include Inc/Stm32f103c6_Drivers/MCAL/EXTI_And_AFIO/subdir.mk
-include Inc/Stm32f103c6_Drivers/MCAL/DIO/subdir.mk
-include Inc/Stm32f103c6_Drivers/LIP/subdir.mk
-include Inc/Stm32f103c6_Drivers/HAL/LCD/subdir.mk
-include Inc/Stm32f103c6_Drivers/HAL/KPD/subdir.mk
-include Inc/Stm32f103c6_Drivers/APP/KPD&LCD&SEG/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := IRQ
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
IRQ.elf \

MAP_FILES += \
IRQ.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
IRQ.list \


# All Target
all: main-build

# Main-build Target
main-build: IRQ.elf secondary-outputs

# Tool invocations
IRQ.elf IRQ.map: $(OBJS) $(USER_OBJS) D:\ARM_Course\ARM_Projects\IRQ\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-2 -o "IRQ.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\ARM_Course\ARM_Projects\IRQ\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="IRQ.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

IRQ.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "IRQ.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) IRQ.elf IRQ.list IRQ.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
