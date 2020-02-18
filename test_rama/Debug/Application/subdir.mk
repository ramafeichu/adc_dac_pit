################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/app_ADC.c \
../Application/app_DAC.c \
../Application/app_GPIO.c \
../Application/app_PIT.c \
../Application/app_buffer.c 

OBJS += \
./Application/app_ADC.o \
./Application/app_DAC.o \
./Application/app_GPIO.o \
./Application/app_PIT.o \
./Application/app_buffer.o 

C_DEPS += \
./Application/app_ADC.d \
./Application/app_DAC.d \
./Application/app_GPIO.d \
./Application/app_PIT.d \
./Application/app_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o: ../Application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../Application -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../component/lists -I../component/uart -I../utilities -I../board/boards -I"C:\Users\Rama\Documents\MCUXpressoIDE_11.0.1_2563\workspace\test_rama\Application" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


