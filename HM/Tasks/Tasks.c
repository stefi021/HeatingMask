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
#include "Adc.h"
#include "HC05.h"

uint8_t MAX_TEMP = 50;
uint8_t PWM = 0;

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;

struct ntc_sensor ntc_sensors[6];
uint8_t msg[17];
char myString[3];


void initTasks(void)
{
	TaskHandle_t ADC_handle;
	TaskHandle_t UART_handle;
	TaskHandle_t Switch_handle;

	BaseType_t status;

	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

	setPWM(0);

	status = xTaskCreate(adc_handler, "LED-Task", 200, NULL, 2, &ADC_handle);
	configASSERT(status == pdPASS);
	status = xTaskCreate(uart_handler, "UART-Task", 200, NULL, 2, &UART_handle);
	configASSERT(status == pdPASS);
	status = xTaskCreate(switch_handler, "Switch-Task", 200, NULL, 2, &Switch_handle);
	configASSERT(status == pdPASS);

	vTaskStartScheduler();
}

 void adc_handler(void *parameters)
{
	static uint8_t i = 0;
	while(1)
	{
		updateSensors(ntc_sensors);

		for(i = 0; i < 1; i++)
		{
			if(ntc_sensors[i].Temp_C > MAX_TEMP)
			{
//				sprintf(msg,"ERROR: OVERTEMPERATURE");
//				HAL_UART_Transmit(&huart1, msg, sizeof(msg)+5, HAL_MAX_DELAY);
//				HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 3, 1000);
//				HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET);
			}
		}

		vTaskDelay(250);
	}
}

 void uart_handler(void *parameters)
{
		static char ch = '1';
		while(1)
		{
			ch= GetChar();
			if(ch == '1')
			{
				sendDataOverBT(ntc_sensors);
	//			for(i = 0; i < 6; i++)
	//			{
	//				sprintf(msg,"TEMP[%d] = %.2f\n\r",i, ntc_sensors[i].Temp_C);
	//				HAL_UART_Transmit(&huart2, msg, sizeof(msg), 10);
	//			}
			}
			else if(ch == '2')
			{
				sprintf((char*)msg,"Write MAX TEMP:");
				HAL_UART_Transmit(&huart1, msg, sizeof(msg)+5, HAL_MAX_DELAY);
				//HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 3, 1000);

				GetString(myString, 3);
				MAX_TEMP = atoi(myString);

			}
			else if(ch == '3')
				setPWM(100);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
//				setPWM(100);

			else if(ch == '4')
				setPWM(0);
//				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
//				setPWM(0);
//			else if(ch == '5')
//			{
//				sprintf((char*)msg,"Write MAX TEMP:");
//				HAL_UART_Transmit(&huart1, msg, sizeof(msg)+5, HAL_MAX_DELAY);
//				//HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 3, 1000)
//				GetString(myString, 3);
//				PWM = atoi(myString);
//				setPWM((float)PWM);
//			}

			vTaskDelay(750);
		}
}

void switch_handler(void *parameters)
{
	static uint8_t positions[4];
	static uint8_t switch_position = 0;

	while(1)
	{
		positions[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		positions[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
		positions[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
		positions[3] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);

		switch_position = (positions[0] << 3) | (positions[1] << 2) | (positions[2] << 1) | (positions[3]);

		switch(switch_position)
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



