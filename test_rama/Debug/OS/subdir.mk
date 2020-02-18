################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/OS_Sched_Core.c \
../OS/OS_Sched_Tasks.c 

OBJS += \
./OS/OS_Sched_Core.o \
./OS/OS_Sched_Tasks.o 

C_DEPS += \
./OS/OS_Sched_Core.d \
./OS/OS_Sched_Tasks.d 


# Each subdirectory must supply rules for building sources it contributes
OS/%.o: ../OS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I../board -I../Application -I../OS -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/serial_manager -I../component/lists -I../component/uart -I../utilities -I../board/boards -I"C:\Users\Rama\Documents\MCUXpressoIDE_11.0.1_2563\workspace\test_rama\Application" -I"C:\Users\Rama\Documents\MCUXpressoIDE_11.0.1_2563\workspace\test_rama\OS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


