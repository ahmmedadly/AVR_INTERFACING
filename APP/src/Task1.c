/*
 * DIO.c
 *
 * Created: 12/17/2024 1:28:18 PM
 * Author : Ahmed Adly
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "mdio.h"


int Task1_Run(void)
{
	 MDIO_enuSetPinConfiguration(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_OUTPUT);
    while (1) 
    {
	MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
	    _delay_ms(1000);
	MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_LOW);
		_delay_ms(1000);


    }
}

