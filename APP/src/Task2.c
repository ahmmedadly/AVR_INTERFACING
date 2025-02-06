/*
 * Task2.c
 *
 * Created: 12/23/2024 11:19:49 PM
 *  Author: Ahmed Adly
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "mdio.h"


// Define the button and LED configurations
#define BUTTON_PORT MDIO_PORTD
#define BUTTON_PIN  MDIO_PIN0
#define LED_PORT    MDIO_PORTB

int Task2_Run(void) {
	u8 buttonState = MDIO_PIN_HIGH;  
	u8 prevButtonState = MDIO_PIN_HIGH;
	u8 counter = 0;           

	MDIO_enuSetPortConfiguration(LED_PORT, MDIO_PIN_OUTPUT);

	MDIO_enuSetPinConfiguration(BUTTON_PORT, BUTTON_PIN, MDIO_PIN_INPUT_PULLUP);

	while (1) {

		MDIO_enuGetPinValue(BUTTON_PORT, BUTTON_PIN, &buttonState);
		if (buttonState == MDIO_PIN_LOW && prevButtonState == MDIO_PIN_HIGH) {
			counter++;
			MDIO_enuSetPortValue(LED_PORT, counter);
		}

		prevButtonState = buttonState;
	}

	return 0; 
}
