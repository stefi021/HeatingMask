################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HM/Drivers/Adc.c \
../HM/Drivers/HC05.c 

OBJS += \
./HM/Drivers/Adc.o \
./HM/Drivers/HC05.o 

C_DEPS += \
./HM/Drivers/Adc.d \
./HM/Drivers/HC05.d 


# Each subdirectory must supply rules for building sources it contributes
HM/Drivers/%.o HM/Drivers/%.su HM/Drivers/%.cyclo: ../HM/Drivers/%.c HM/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/HM/Drivers" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/HM/Tasks" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS/include" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HM-2f-Drivers

clean-HM-2f-Drivers:
	-$(RM) ./HM/Drivers/Adc.cyclo ./HM/Drivers/Adc.d ./HM/Drivers/Adc.o ./HM/Drivers/Adc.su ./HM/Drivers/HC05.cyclo ./HM/Drivers/HC05.d ./HM/Drivers/HC05.o ./HM/Drivers/HC05.su

.PHONY: clean-HM-2f-Drivers

