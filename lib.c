/*
 * lib.c
 *
 *  Created on: 28.08.2018
 */

#include <LIB/lib.h>
#include <stdio.h>
#include "stm32f10x.h"

/*
void SetPin(GPIO_TypeDef* port , uint16_t pin)
{
	port->ODR = pin;
}
*/

void ConfigPin(GPIO_TypeDef* port, uint8_t pin , uint8_t mode)
{
	if(pin<8)	//Rejestr Low - dla pinów 0-7
	{
		port->CRL &= ~(0b1111<<(pin*4));		//zerowanie bitów (domyślnie są ustawione 0100?)
		port->CRL |= (mode<<(pin*4));			//zapis konfiguracji trybu pracy pinu do pamięci
	}
	else		//Rejestr High - dla pinów 8-15
	{
		port->CRH &= ~(0b1111<<((pin-8)*4));	//zerowanie bitów
		port->CRH |= (mode<<((pin-8)*4));		//zapis konfiguracji
	}
}


