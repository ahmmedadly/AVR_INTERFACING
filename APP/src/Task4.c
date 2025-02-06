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


// Runtime function
void App_Run(void)
{
    u8 switchState;

    while (1)
    {

    }
}

int Task3_Run(void)
{
    App_Init();  // Initialize configurations with MPORT
    App_Run();   // Control LEDs and switches dynamically with MDIO
    return 0;
}
