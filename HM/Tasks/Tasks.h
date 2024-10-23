/*
 * Tasks.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */

#ifndef TASKS_TASKS_H_
#define TASKS_TASKS_H_


void initTasks(void);
void adc_handler(void *parameters);
void uart_handler(void *parameters);
void switch_handler(void *parameters);
void setPWM(float dc);

#endif /* TASKS_TASKS_H_ */
