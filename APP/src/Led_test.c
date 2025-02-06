#include "led.h"
#include "led-cfg.h"
#include "STD_TYPES.h"


int Led_run() {
    // Initialize LEDs
    LED_enuErrorStatus_t status = LED_vInit();
    if (status != LED_OK) {
        // Handle initialization error
    }

    // Turn on LED 1
    status = LED_SetState(LED_1, 1); // Turn on LED 1
    if (status != LED_OK) {
        // Handle error
    }

    // Turn off LED 2
    status = LED_SetState(LED_2, 0); // Turn off LED 2
    if (status != LED_OK) {
        // Handle error
    }

    // Toggle LED 3
    status = LED_SetState(LED_3, 1); // Turn on LED 3
    if (status != LED_OK) {
        // Handle error
    }

    return 0;
}