################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/relay_module_c_files/relay_module.c 

OBJS += \
./example/relay_module_c_files/relay_module.o 

C_DEPS += \
./example/relay_module_c_files/relay_module.d 


# Each subdirectory must supply rules for building sources it contributes
example/relay_module_c_files/%.o: ../example/relay_module_c_files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_chip_175x_6x\inc" -I"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_board_nxp_lpcxpresso_1769\inc" -I"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\relay_app\example\inc" -I"C:\Users\ndjekic\Documents\LPCXpresso_8.1.4_606\LPCOpen\lpc_chip_175x_6x\inc\usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

