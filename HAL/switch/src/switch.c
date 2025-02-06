// /*
//  * Switch.c
//  * Ahmed Adly
//  * Created: 12/25/2024 11:58:26 AM

#include "switch.h"
#include "switch_cfg.h"
#include "mdio.h"
#include "LIB/STD_TYPES.h"

void SWITCH_vInit(void)
{
    u8 i;
    for (i = 0; i < NUM_OF_SWITCHES; i++)
    {
        MDIO_enuSetPinConfiguration(switch_arr[i].PORT, switch_arr[i].PIN, MDIO_PIN_INPUT_PULLUP);
    }
}

u8 SWITCH_u8GetState(u8 SwitchNum, u8 *state)
{
    if (switch_arr[SwitchNum].CONNECTION == PULL_UP)
    {
        MDIO_enuGetPinValue(switch_arr[SwitchNum].PORT, switch_arr[SwitchNum].PIN, state);
    }
    else
    {
        MDIO_enuGetPinValue(switch_arr[SwitchNum].PORT, switch_arr[SwitchNum].PIN, state);
        *state = !*state;
    }
    return *state;
}
