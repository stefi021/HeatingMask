/*
 * HC05.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Z0212095
 */

#include "HC05.h"
#include "main.h"

#include <stdio.h>

extern UART_HandleTypeDef huart1;
uint8_t msg1[17];

char GetChar(void)
{
 	while((huart1.Instance->SR & USART_SR_RXNE) != USART_SR_RXNE);
	return huart1.Instance->DR;
}

void GetString(char* buffer, int maxLength)
{
    int i = 0;
    char receivedChar;

    while ((huart1.Instance->SR & USART_SR_RXNE) != 0)
    {
        char dummy = huart1.Instance->DR; // Čitanje podataka iz RX buffera i odbacivanje
        (void)dummy; // Koristi se dummy promenljiva da bi se izbeglo upozorenje o nepotrebnom promenljivoj
    }

    // Čitanje karaktera sve dok ne pročitamo terminator stringa ('\0') ili dostignemo maksimalnu dužinu
    for(i = 0; i < 3; i++)
    {
    	receivedChar = GetChar();
        // Ako nije null karakter i nismo premašili maksimalnu dužinu, dodajemo karakter u bafer
        if (receivedChar != '\0' && i < maxLength - 1)
        {
            buffer[i] = receivedChar;
        }
        else
        {
            break;  // Ako smo pročitali null karakter ili dostigli maksimalnu dužinu, prekidamo petlju
        }
    }

    // Dodajemo null terminator na kraj stringa
    buffer[i] = '\0';
}

void sendDataOverBT(struct ntc_sensor *temp)
{
	int i = 0;
	for(i = 0; i < 6; i++)
	{
		sprintf((char*)msg1,"TEMP[%d] = %d",i, (int)temp[i].Temp_C);
		HAL_UART_Transmit(&huart1, msg1, sizeof(msg1), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 3, 1000);
	}
}


