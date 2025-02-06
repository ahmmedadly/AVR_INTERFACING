#include "led.h"
#include "led-cfg.h"
#include "mdio.h"
#include "STD_TYPES.h"

/* Initialize LEDs */
LED_enuErrorStatus_t LED_vInit(void) {
    u8 i;
    for (i = 0; i < NUM_OF_LEDS; i++) {
        MDIO_enuErrorStatus_t mdioStatus = MDIO_enuSetPinConfiguration(led_arr[i].PORT, led_arr[i].PIN, MDIO_PIN_OUTPUT);
        if (mdioStatus != MDIO_OK) {
            return LED_NOK; // Return error if GPIO configuration fails
        }
    }
    return LED_OK; // Return success
}

/* Set LED State */
LED_enuErrorStatus_t LED_SetState(u8 LedNum, u8 State) {
    if (LedNum >= NUM_OF_LEDS) {
        return LED_INVALID_PARAM; // Return error if LedNum is out of range
    }

    if (led_arr[LedNum].CONNECTION == ACTIVE_HIGH) {
        MDIO_enuSetPinValue(led_arr[LedNum].PORT, led_arr[LedNum].PIN, State);
    } else {
        MDIO_enuSetPinValue(led_arr[LedNum].PORT, led_arr[LedNum].PIN, !State);
    }

    return LED_OK; // Return success
}