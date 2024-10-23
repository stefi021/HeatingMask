/*
 * Adc.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */


#include "Adc.h"
#include "math.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;

uint16_t adc_result_dma[6];

float Vsupply = 3.3;    //power supply voltage (3.3 V rail) -STM32 ADC pin is NOT 5 V tolerant
float R_10k = 19840;    //10k resistor measured resistance in Ohms (other element in the voltage divider)
float B_param = 3700;   //B-coefficient of the thermistor
float T0 = 298.15;      //25°C in Kelvin

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
//{
////	readFromAdc(temp);
//}


void readFromAdc(struct ntc_sensor *NTC_SENS)
{
	uint8_t i = 0;

	for(i = 0; i < 6; i++)
	{
		NTC_SENS[i].Vout = adc_result_dma[i];
		NTC_SENS[i].Vout = NTC_SENS[i].Vout * (3.3/4095);
		NTC_SENS[i].R_NTC = (NTC_SENS[i].Vout * R_10k) / (Vsupply - NTC_SENS[i].Vout);
		NTC_SENS[i].Temp_K = (T0 * B_param) / (T0 * log(NTC_SENS[i].R_NTC / R_10k) + B_param);
		NTC_SENS[i].Temp_C = NTC_SENS[i].Temp_K - 273.15;
	}
}


void updateSensors(struct ntc_sensor *temp)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_result_dma, 6);
	readFromAdc(temp);
}


