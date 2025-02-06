/*
 * Task3.c
 *
 * Created: 12/25/2024 11:58:26 AM
 *  Author: Ahmed Adly
 */

#define F_CPU 8000000
#include "mdio.h"
#include "mport.h"
#include <util/delay.h>


// Define switch pins
#define SWITCH0_PIN 0x00 // PA0
#define SWITCH1_PIN 0x01 // PA1
#define SWITCH2_PIN 0x02 // PA2

// Define LED pins
#define LED0_PIN 0x10 // PB0
#define LED1_PIN 0x11 // PB1
#define LED2_PIN 0x12 // PB2

// Initialization function
void App_Init(void)
{
    // Use MPORT for initialization
    // Configure switches as input with pull-up
    MPORT_enuSetPinDir(SWITCH0_PIN, MPORT_enu_dir_INPUT);
    MPORT_enuSetPinMode(SWITCH0_PIN, MPORT_enu_INPUT_PULLUP);

    MPORT_enuSetPinDir(SWITCH1_PIN, MPORT_enu_dir_INPUT);
    MPORT_enuSetPinMode(SWITCH1_PIN, MPORT_enu_INPUT_PULLUP);

    MPORT_enuSetPinDir(SWITCH2_PIN, MPORT_enu_dir_INPUT);
    MPORT_enuSetPinMode(SWITCH2_PIN, MPORT_enu_INPUT_PULLUP);

    // Configure LEDs as output
    MPORT_enuSetPinDir(LED0_PIN, MPORT_enu_dir_OUTPUT);
    MPORT_enuSetPinDir(LED1_PIN, MPORT_enu_dir_OUTPUT);
    MPORT_enuSetPinDir(LED2_PIN, MPORT_enu_dir_OUTPUT);
}

// Runtime function
void App_Run(void)
{
    u8 switchState;

    while (1)
    {
        // Use MDIO for dynamic control
        // Check switch 0 and control LED 0
        MDIO_enuGetPinValue(MDIO_PORTA, 0, &switchState);
        MDIO_enuSetPinValue(MDIO_PORTB, 0, switchState);

        // Check switch 1 and control LED 1
        MDIO_enuGetPinValue(MDIO_PORTA, 1, &switchState);
        MDIO_enuSetPinValue(MDIO_PORTB, 1, switchState);

        // Check switch 2 and control LED 2
        MDIO_enuGetPinValue(MDIO_PORTA, 2, &switchState);
        MDIO_enuSetPinValue(MDIO_PORTB, 2, switchState);
    }
}

int Task3_Run(void)
{
    App_Init();  // Initialize configurations with MPORT
    App_Run();   // Control LEDs and switches dynamically with MDIO
    return 0;
}
