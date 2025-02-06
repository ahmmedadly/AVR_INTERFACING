/*
 * port.c
 *
 * Created: 1/6/2024
 * Author: Ahmed Adly
 */
#include "mport.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define DDRA        *((volatile u8*)0x3A)
#define DDRB        *((volatile u8*)0x37)
#define DDRC        *((volatile u8*)0x34)
#define DDRD        *((volatile u8*)0x31)

#define PORTA_REG   *((volatile u8*)0x3B)
#define PORTB_REG   *((volatile u8*)0x38)
#define PORTC_REG   *((volatile u8*)0x35)
#define PORTD_REG   *((volatile u8*)0x32)

typedef struct{
    volatile u8 PIN;
    volatile u8 DDR;
    volatile u8 PORT;
}MPORT_Registers_t;

MPORT_getPinCFG_t MPORT_garrPin_CFG[TOTAL_NO_OF_PORTS*TOTAL_NO_OF_PINS] = {
    // Port A (Port 0)
    {.pin = PIN_A0, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A1, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A2, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A3, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A4, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A5, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A6, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_A7, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},

    // Port B (Port 1)
    {.pin = PIN_B0, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B1, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B2, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B3, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B4, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B5, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B6, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_B7, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},

    // Port C (Port 2)
    {.pin = PIN_C0, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C1, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C2, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C3, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C4, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C5, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C6, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_C7, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},

    // Port D (Port 3)
    {.pin = PIN_D0, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D1, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D2, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D3, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D4, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D5, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D6, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT},
    {.pin = PIN_D7, .mode = MPORT_enu_INPUT_PULLUP, .dir = MPORT_enu_dir_INPUT}
};


MPORT_enuErorrStatus_t MPORT_enuSetPinMode(u8 pin_val, u8 mode)
 {
    u8 pinval = (pin_val & 0x0F);
    u8 portval = (pin_val >> 4);
    MPORT_enuErorrStatus_t retStatus= MPORT_enu_OK;
    switch(portval)
    {
        case MPORT_PORTA:
            switch (mode){
                case MPORT_enu_INPUT_PULLUP:
                    SET_BIT(PORTA_REG,pinval);
                    break;
                case MPORT_enu_INPUT_PULLDOWN:
                    CLR_BIT(PORTA_REG,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
                return retStatus;
            }
        break;

        case MPORT_PORTB:
            switch (mode){
                case MPORT_enu_INPUT_PULLUP:
                    SET_BIT(PORTB_REG,pinval);
                    break;
                case MPORT_enu_INPUT_PULLDOWN:
                    CLR_BIT(PORTB_REG,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;

        case MPORT_PORTC:
            switch (mode){
                case MPORT_enu_INPUT_PULLUP:
                    SET_BIT(PORTC_REG,pinval);
                    break;
                case MPORT_enu_INPUT_PULLDOWN:
                    CLR_BIT(PORTC_REG,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;

        case MPORT_PORTD:
            switch (mode){
                case MPORT_enu_INPUT_PULLUP:
                    SET_BIT(PORTD_REG,pinval);
                    break;
                case MPORT_enu_INPUT_PULLDOWN:
                    CLR_BIT(PORTD_REG,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;

        default:
            retStatus= MPORT_enu_NOT_AVAILABLE;
    }
}


MPORT_enuErorrStatus_t MPORT_enuSetPinDir(u8 pin_val, u8 dir){
    u8 pinval = (pin_val & 0x0F);
    u8 portval = (pin_val >> 4);
    MPORT_enuErorrStatus_t retStatus= MPORT_enu_OK;

    switch(portval)
    {
        case MPORT_PORTA:
            switch (dir){
                case MPORT_enu_dir_INPUT:
                    CLR_BIT(DDRA,pinval);
                    break;
                case MPORT_enu_dir_OUTPUT:
                    SET_BIT(DDRA,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;
        case MPORT_PORTB:
            switch (dir){
                case MPORT_enu_dir_INPUT:
                    CLR_BIT(DDRB,pinval);
                    break;
                case MPORT_enu_dir_OUTPUT:
                    SET_BIT(DDRB,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;
        case MPORT_PORTC:
            switch (dir){
                case MPORT_enu_dir_INPUT:
                    CLR_BIT(DDRC,pinval);
                    break;
                case MPORT_enu_dir_OUTPUT:
                    SET_BIT(DDRC,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;
        case MPORT_PORTD:
            switch (dir){
                case MPORT_enu_dir_INPUT:
                    CLR_BIT(DDRD,pinval);
                    break;
                case MPORT_enu_dir_OUTPUT:
                    SET_BIT(DDRD,pinval);
                    break;
                default:
                    retStatus = MPORT_enu_NOT_AVAILABLE;
            }
            break;
        default:
            retStatus = MPORT_enu_NOT_AVAILABLE;
    return retStatus;
}
    return retStatus;
}
    
void MPORT_vInit(void)
{
    u8 pinIndex;
    for(pinIndex=0;pinIndex<32;pinIndex++)
    {
        MPORT_enuSetPinDir(MPORT_garrPin_CFG[pinIndex].pin,MPORT_garrPin_CFG[pinIndex].dir);
        MPORT_enuSetPinMode(MPORT_garrPin_CFG[pinIndex].pin, MPORT_garrPin_CFG[pinIndex].mode);
    }
}
