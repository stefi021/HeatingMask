/*
 * Task.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Korisnik
 */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#include "Tasks.h"
#include "PositionButton.h"


uint8_t MAX_TEMP = 50;
uint8_t PWM = 0;

extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;

uint8_t ntc_sensors[6];
uint8_t msg[17];
char myString[3];
int i = 0;

void UART_Clear_Receive_Buffer(UART_HandleTypeDef *huart);

void initTasks(void)
{

	TaskHandle_t UART_handle;
	TaskHandle_t Switch_handle;

	BaseType_t status;

	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

	setPWM(0);

	status = xTaskCreate(uart_handler, "UART-Task", 200, NULL, 2, &UART_handle);
	configASSERT(status == pdPASS);
	status = xTaskCreate(switch_handler, "Switch-Task", 200, NULL, 2, &Switch_handle);
	configASSERT(status == pdPASS);

	vTaskStartScheduler();
}


 void uart_handler(void *parameters)
{
	while(1)
	{
		HAL_UART_Receive_IT(&huart1, ntc_sensors, sizeof(ntc_sensors));
		vTaskDelay(750);
	}
}

void switch_handler(void *parameters)
{

	static uint8_t position = 0;

	while(1)
	{

		position = getPosition();

		switch(position)
		{
	    case 0x0D:
	        printf("Switch position: 0\n");
	        setPWM(0);
	        break;
	    case 0xF:
	        printf("Switch position: 1\n");
	        setPWM(90);
	        break;
	    case 0x0B:
	        printf("Switch position: 2\n");
	        setPWM(100);
	        break;
	    default:
	        printf("Switch position: undefined\n");
	        setPWM(100);
	        break;
		}
		vTaskDelay(500);
	}


}

void setPWM(float dc)
{
    uint16_t counterTicks = (dc * 7680) / 100;

//    htim1->Instance->CCR1 = counterTicks;
    htim2.Instance->CCR1 = counterTicks;

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) // Check if the interrupt is from USART1
    {
    	for(i = 0; i < 6; i++){
    		ntc_sensors[i] = 0;
    	}
    }
}
