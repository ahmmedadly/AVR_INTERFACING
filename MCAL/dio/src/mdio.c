/*
 * MDIO.c
 *
 * Created: 12/17/2024
 * Author: AHMED ADLY
 */

#include "mdio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

MDIO_enuErrorStatus_t MDIO_enuSetPinConfiguration(MDIO_enuPortNum_t Copy_enuPortNum,
 MDIO_enuPinNum_t Copy_enuPinNum,
 MDIO_enuPinConfig_t Copy_enuConfig)
{
    // Validate parameters
    if (Copy_enuPortNum >= MDIO_TOTAL_PORTS)
    {
        return MDIO_INVALID_PARAM;
    }

    if (Copy_enuPinNum >= MDIO_TOTAL_PINS)
    {
        return MDIO_INVALID_PARAM;
    }

    switch (Copy_enuPortNum)
    {
    case MDIO_PORTA:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            CLR_BIT (DDRA ,Copy_enuPinNum);
            CLR_BIT (PORTA_REG ,Copy_enuPinNum); // Disable pull-up
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            SET_BIT (DDRA ,Copy_enuPinNum);
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            CLR_BIT (DDRA ,Copy_enuPinNum);
            SET_BIT (PORTA_REG ,Copy_enuPinNum); // Enable pull-up
        }
        break;
        case MDIO_PORTB:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            CLR_BIT (DDRB ,Copy_enuPinNum);
            CLR_BIT (PORTB_REG ,Copy_enuPinNum); // Disable pull-up
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            SET_BIT (DDRB ,Copy_enuPinNum);
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            CLR_BIT (DDRB ,Copy_enuPinNum);
            SET_BIT (PORTB_REG ,Copy_enuPinNum); // Enable pull-up
        }
        break;
        case MDIO_PORTC:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            CLR_BIT (DDRC ,Copy_enuPinNum);
            CLR_BIT (PORTC_REG ,Copy_enuPinNum); // Disable pull-up
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            SET_BIT (DDRC ,Copy_enuPinNum);
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            CLR_BIT (DDRC ,Copy_enuPinNum);
            SET_BIT (PORTC_REG ,Copy_enuPinNum); // Enable pull-up
        }
        break;
        case MDIO_PORTD:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            CLR_BIT (DDRD ,Copy_enuPinNum);
            CLR_BIT (PORTD_REG ,Copy_enuPinNum); // Disable pull-up
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            SET_BIT (DDRD ,Copy_enuPinNum);
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            CLR_BIT (DDRD ,Copy_enuPinNum);
            SET_BIT (PORTD_REG ,Copy_enuPinNum); // Enable pull-up
        }
        break;

      default:
        return MDIO_INVALID_PARAM;
    }

    return MDIO_OK;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortConfiguration(MDIO_enuPortNum_t Copy_enuPortNum,
                                                   MDIO_enuPinConfig_t Copy_enuConfig)
{
    if (Copy_enuPortNum >= MDIO_TOTAL_PORTS)
    {
        return MDIO_INVALID_PARAM;
    }

    switch (Copy_enuPortNum)
    {
    case MDIO_PORTA:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            DDRA = 0x00;
            PORTA_REG = 0x00;
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            DDRA = 0xFF;
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            DDRA = 0x00;
            PORTA_REG = 0xFF;
        }
        break;

    case MDIO_PORTB:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            DDRB = 0x00;
            PORTB_REG = 0x00;
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            DDRB = 0xFF;
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            DDRB = 0x00;
            PORTB_REG = 0xFF;
        }
        break;

    case MDIO_PORTC:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            DDRC = 0x00;
            PORTC_REG = 0x00;
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            DDRC = 0xFF;
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            DDRC = 0x00;
            PORTC_REG = 0xFF;
        }
        break;

    case MDIO_PORTD:
        if (Copy_enuConfig == MDIO_PIN_INPUT_FLOAT)
        {
            DDRD = 0x00;
            PORTD_REG = 0x00;
        }
        else if (Copy_enuConfig == MDIO_PIN_OUTPUT)
        {
            DDRD = 0xFF;
        }
        else if (Copy_enuConfig == MDIO_PIN_INPUT_PULLUP)
        {
            DDRD = 0x00;
            PORTD_REG = 0xFF;
        }
        break;

    default:
        return MDIO_INVALID_PARAM;
    }

    return MDIO_OK;
}

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,
                                          MDIO_enuPinNum_t Copy_enuPinNum,
                                          MDIO_enuPinState_t Copy_enuState)
{
    if (Copy_enuPortNum >= MDIO_TOTAL_PORTS)
    {
        return MDIO_INVALID_PARAM;
    }

    if (Copy_enuPinNum >= MDIO_TOTAL_PINS)
    {
        return MDIO_INVALID_PARAM;
    }

    switch (Copy_enuPortNum)
    {
    case MDIO_PORTA:
    if (Copy_enuState == MDIO_PIN_HIGH)
    {
        SET_BIT (PORTA_REG ,Copy_enuPinNum);
    }
    else
    {
        CLR_BIT (PORTA_REG ,Copy_enuPinNum);
    }
    break;
    case MDIO_PORTB:
    
    if (Copy_enuState == MDIO_PIN_HIGH)
    {
        SET_BIT (PORTB_REG ,Copy_enuPinNum);
    }
    else
    {
        CLR_BIT (PORTB_REG ,Copy_enuPinNum);
    }
    break;
    case MDIO_PORTC:
    if (Copy_enuState == MDIO_PIN_HIGH)
    {
        SET_BIT (PORTC_REG ,Copy_enuPinNum);
    }
    else
    {
        CLR_BIT (PORTC_REG ,Copy_enuPinNum);
    }
    break;
    case MDIO_PORTD:
    if (Copy_enuState == MDIO_PIN_HIGH)
    {
        SET_BIT (PORTD_REG ,Copy_enuPinNum);
    }
    else
    {
        CLR_BIT (PORTD_REG ,Copy_enuPinNum);
    }
    break;
    default:
        return MDIO_INVALID_PARAM;

    }

    return MDIO_OK;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,
                                           u8 Copy_u8Value)
{
    if (Copy_enuPortNum >= MDIO_TOTAL_PORTS)
    {
        return MDIO_INVALID_PARAM;
    }

    switch (Copy_enuPortNum)
    {
    case MDIO_PORTA:
        PORTA_REG = Copy_u8Value;
        break;

    case MDIO_PORTB:
        PORTB_REG = Copy_u8Value;
        break;

    case MDIO_PORTC:
        PORTC_REG = Copy_u8Value;
        break;

    case MDIO_PORTD:
        PORTD_REG = Copy_u8Value;
        break;

    default:
        return MDIO_INVALID_PARAM;
    }

    return MDIO_OK;
}


MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,
                                          MDIO_enuPinNum_t Copy_enuPinNum,
                                          u8 *Add_pu8PinValue)
{ 
    if (Add_pu8PinValue == MDIO_NULL_PTR)
    {
        return MDIO_NULL_PTR;
    }

    if (Copy_enuPortNum >= MDIO_TOTAL_PORTS)
    {
        return MDIO_INVALID_PARAM;
    }

    if (Copy_enuPinNum >= MDIO_TOTAL_PINS)
    {
        return MDIO_INVALID_PARAM;
    }

    switch (Copy_enuPortNum)
    {

    case MDIO_PORTA:

        *Add_pu8PinValue = (GET_BIT(PINA_REG ,Copy_enuPinNum));
        break;

    case MDIO_PORTB:
    
            *Add_pu8PinValue = (GET_BIT(PINB_REG ,Copy_enuPinNum));
            break;

    case MDIO_PORTC:
        
                *Add_pu8PinValue = (GET_BIT(PINC_REG ,Copy_enuPinNum));
                break;

    case MDIO_PORTD:
        
                    *Add_pu8PinValue = (GET_BIT(PIND_REG ,Copy_enuPinNum));
                    break;

    default:
        return MDIO_INVALID_PARAM;
    }

    return MDIO_OK;
}

