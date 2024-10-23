################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HM/Tasks/Tasks.c 

OBJS += \
./HM/Tasks/Tasks.o 

C_DEPS += \
./HM/Tasks/Tasks.d 


# Each subdirectory must supply rules for building sources it contributes
HM/Tasks/%.o HM/Tasks/%.su HM/Tasks/%.cyclo: ../HM/Tasks/%.c HM/Tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/HM/Drivers" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/HM/Tasks" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS/include" -I"C:/Users/Z0212095/STM32CubeIDE/workspace_1.14.0/HeatingMask/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HM-2f-Tasks

clean-HM-2f-Tasks:
	-$(RM) ./HM/Tasks/Tasks.cyclo ./HM/Tasks/Tasks.d ./HM/Tasks/Tasks.o ./HM/Tasks/Tasks.su

.PHONY: clean-HM-2f-Tasks

