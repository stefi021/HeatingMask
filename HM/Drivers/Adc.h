/*
 * Adc.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */

#include "main.h"

// Postavite include guards iznad definicije strukture
#ifndef NTC_SENSOR_DEFINED
#define NTC_SENSOR_DEFINED
struct ntc_sensor
{
	float Vout;  //Voltage divider output
	float R_NTC; //NTC thermistor resistance in Ohms
	float Temp_K; //Temperature measured by the thermistor (Kelvin)
	float Temp_C; //Temperature measured by the thermistor (Celsius)
};
#endif  // NTC_SENSOR_DEFINED

void readFromAdc(struct ntc_sensor *NTC_SENS);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void updateSensors(struct ntc_sensor *temp);


