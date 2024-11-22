################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HM/Drivers/PositionButton.c \
../HM/Drivers/Uart.c 

OBJS += \
./HM/Drivers/PositionButton.o \
./HM/Drivers/Uart.o 

C_DEPS += \
./HM/Drivers/PositionButton.d \
./HM/Drivers/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
HM/Drivers/%.o HM/Drivers/%.su HM/Drivers/%.cyclo: ../HM/Drivers/%.c HM/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"/home/stefan/STM32CubeIDE/workspace_1.16.0/HeatingMask/HM/Drivers" -I"/home/stefan/STM32CubeIDE/workspace_1.16.0/HeatingMask/HM/Tasks" -I"/home/stefan/STM32CubeIDE/workspace_1.16.0/HeatingMask/ThirdParty/FreeRTOS" -I"/home/stefan/STM32CubeIDE/workspace_1.16.0/HeatingMask/ThirdParty/FreeRTOS/include" -I"/home/stefan/STM32CubeIDE/workspace_1.16.0/HeatingMask/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HM-2f-Drivers

clean-HM-2f-Drivers:
	-$(RM) ./HM/Drivers/PositionButton.cyclo ./HM/Drivers/PositionButton.d ./HM/Drivers/PositionButton.o ./HM/Drivers/PositionButton.su ./HM/Drivers/Uart.cyclo ./HM/Drivers/Uart.d ./HM/Drivers/Uart.o ./HM/Drivers/Uart.su

.PHONY: clean-HM-2f-Drivers

