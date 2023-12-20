################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_MASTERING.lss \

FLASH_IMAGE += \
AVR_MASTERING.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: AVR_MASTERING.elf secondary-outputs

# Tool invocations
AVR_MASTERING.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_MASTERING.map -mmcu=atmega32 -o "AVR_MASTERING.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_MASTERING.lss: AVR_MASTERING.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_MASTERING.elf  >"AVR_MASTERING.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_MASTERING.hex: AVR_MASTERING.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_MASTERING.elf  "AVR_MASTERING.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_MASTERING.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_MASTERING.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: AVR_MASTERING.elf
	@echo 'Invoking: AVRDude'
	D:\Embeded\Tools\IMT_SDK_Win_32\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:AVR_MASTERING.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_MASTERING.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
