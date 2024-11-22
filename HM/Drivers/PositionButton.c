/*
 * Adc.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */
#include "PositionButton.h"

uint8_t getPosition(void)
{
	static uint8_t positions[4];
	static uint8_t switch_position = 0;

	positions[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
	positions[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
	positions[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
	positions[3] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);

	switch_position = (positions[0] << 3) | (positions[1] << 2) | (positions[2] << 1) | (positions[3]);

	return switch_position;
}

