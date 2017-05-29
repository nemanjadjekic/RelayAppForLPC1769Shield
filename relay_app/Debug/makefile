################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/usb_driver_c_files/subdir.mk
-include example/relay_module_c_files/subdir.mk
-include example/main/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: relay_app.axf

# Tool invocations
relay_app.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_chip_175x_6x\Debug" -L"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_board_nxp_lpcxpresso_1769\Debug" -L"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_chip_175x_6x\libs" -Xlinker -Map="relay_app.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "usbd_lib_cdc_Debug.ld" -o "relay_app.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) relay_app.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "relay_app.axf"; # arm-none-eabi-objcopy -v -O binary "relay_app.axf" "relay_app.bin" ; # checksum -p LPC1769 -d "relay_app.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
