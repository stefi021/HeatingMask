/*
 * HC05.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */

#ifndef DRIVERS_HC05_H_
#define DRIVERS_HC05_H_

#include "Adc.h"

char GetChar(void);
void GetString(char* buffer, int maxLength);
void sendDataOverBT(struct ntc_sensor *temp);


#endif /* DRIVERS_HC05_H_ */
