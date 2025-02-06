#include "HAL/led/inc/led.h"
#include "LIB/STD_TYPES.h"
#include "HAL/led/inc/led-cfg.h"
#include "HAL/switch/inc/switch.h"
#include "STD_TYPES.h"

int LedSwitch_run() {
    u8 switchState;
    LED_enuErrorStatus_t ledStatus;
    SWITCH_enuErrorStatus_t switchStatus;

    // Initialize LEDs and switches
    ledStatus = LED_vInit();
    switchStatus = SWITCH_vInit();

    if (ledStatus != LED_OK || switchStatus != SWITCH_OK)
    {
        // Handle initialization error
    }

    // Read switch state and control LEDs
    while (1) {
        switchStatus = SWITCH_u8GetState(SWITCH_1, &switchState);
        if (switchStatus == SWITCH_OK) {
            // Turn on LED 1 if switch is pressed
            ledStatus = LED_SetState(LED_1, switchState);
            if (ledStatus != LED_OK) 
            {
                // Handle LED error
            }
        } else 
        {
            // Handle switch read error
        }
    }

    return 0;
}