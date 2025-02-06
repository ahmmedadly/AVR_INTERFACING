/*
 * MDIO.h
 *
 * Created: 12/17/2024 1:32:17 PM
 * Author: AHMED ADLY
 */

#ifndef MDIO_H_
#define MDIO_H_

/* Type definitions */
typedef  unsigned char u8;

/* Register Definitions */
#define DDRA        *((volatile u8*)0x3A)
#define DDRB        *((volatile u8*)0x37)
#define DDRC        *((volatile u8*)0x34)
#define DDRD        *((volatile u8*)0x31)

#define PORTA_REG   *((volatile u8*)0x3B)
#define PORTB_REG   *((volatile u8*)0x38)
#define PORTC_REG   *((volatile u8*)0x35)
#define PORTD_REG   *((volatile u8*)0x32)

#define PINA_REG    *((volatile u8*)0x39)
#define PINB_REG    *((volatile u8*)0x36)
#define PINC_REG    *((volatile u8*)0x33)
#define PIND_REG    *((volatile u8*)0x30)

/* Error Status Type */
typedef enum {
    
    MDIO_NULL_PTR,
    MDIO_OK,
    MDIO_INVALID_PARAM,
    MDIO_NOK
} MDIO_enuErrorStatus_t;

/* Port Definitions */
typedef enum {
    MDIO_PORTA,
    MDIO_PORTB,
    MDIO_PORTC,
    MDIO_PORTD,
    MDIO_TOTAL_PORTS
} MDIO_enuPortNum_t;

/* Pin Definitions */
typedef enum {
    MDIO_PIN0,
    MDIO_PIN1,
    MDIO_PIN2,
    MDIO_PIN3,
    MDIO_PIN4,
    MDIO_PIN5,
    MDIO_PIN6,
    MDIO_PIN7,
    MDIO_TOTAL_PINS
} MDIO_enuPinNum_t;

/* Pin Configurations */
typedef enum {
    MDIO_PIN_INPUT_FLOAT,
    MDIO_PIN_OUTPUT,
    MDIO_PIN_INPUT_PULLUP
} MDIO_enuPinConfig_t;

/* Pin States */
typedef enum {
    MDIO_PIN_LOW,
    MDIO_PIN_HIGH
} MDIO_enuPinState_t;

/* Function Prototypes */
MDIO_enuErrorStatus_t MDIO_enuSetPinConfiguration(
    MDIO_enuPortNum_t Copy_enuPortNum,
    MDIO_enuPinNum_t Copy_enuPinNum,
    MDIO_enuPinConfig_t Copy_enuConfig);

MDIO_enuErrorStatus_t MDIO_enuSetPortConfiguration(
    MDIO_enuPortNum_t Copy_enuPortNum,
    MDIO_enuPinConfig_t Copy_enuConfig);

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(
    MDIO_enuPortNum_t Copy_enuPortNum,
    MDIO_enuPinNum_t Copy_enuPinNum,
    MDIO_enuPinState_t Copy_enuState);

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(
    MDIO_enuPortNum_t Copy_enuPortNum,
    u8 Copy_u8Value);

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(
    MDIO_enuPortNum_t Copy_enuPortNum,
    MDIO_enuPinNum_t Copy_enuPinNum,
    u8* Add_pu8PinValue);

//void MDIO_vInit(void);

#endif /* MDIO_H_ */