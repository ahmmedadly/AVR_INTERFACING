#include "switch_cfg.h"
#include "mdio.h"

/* Switch Configuration Array */
Switch_Cfg_t switch_arr[NUM_OF_SWITCHES] = {
    [SWITCH_1] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN0, .CONNECTION = PULL_UP},
    [SWITCH_2] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN1, .CONNECTION = PULL_UP},
    [SWITCH_3] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN2, .CONNECTION = PULL_UP},
};

/* Initialize Switches */
SWITCH_enuErrorStatus_t SWITCH_vInit(void) {
    u8 i;
    for (i = 0; i < NUM_OF_SWITCHES; i++) {
        MDIO_enuErrorStatus_t mdioStatus = MDIO_enuSetPinConfiguration(switch_arr[i].PORT, switch_arr[i].PIN, MDIO_PIN_INPUT_PULLUP);
        if (mdioStatus != MDIO_OK) {
            return SWITCH_NOK; // Return error if GPIO configuration fails
        }
    }
    return SWITCH_OK; // Return success
}

/* Get Switch State */
SWITCH_enuErrorStatus_t SWITCH_u8GetState(u8 SwitchNum, u8 *state) {
    if (SwitchNum >= NUM_OF_SWITCHES) {
        return SWITCH_INVALID_PARAM; // Return error if SwitchNum is out of range
    }
    if (state == NULL) {
        return SWITCH_NULL_PTR; // Return error if state pointer is NULL
    }

    MDIO_enuErrorStatus_t mdioStatus = MDIO_enuGetPinValue(switch_arr[SwitchNum].PORT, switch_arr[SwitchNum].PIN, state);
    if (mdioStatus != MDIO_OK) {
        return SWITCH_NOK; // Return error if GPIO read fails
    }

    if (switch_arr[SwitchNum].CONNECTION == PULL_UP) {
        *state = !*state; // Invert state for pull-up configuration
    }

    return SWITCH_OK; // Return success
}