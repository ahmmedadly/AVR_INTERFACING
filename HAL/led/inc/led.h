#ifndef _LED_H_
#define _LED_H_

#include "STD_TYPES.h"

/* Error Status Type */
typedef enum {
    LED_NULL_PTR,       // Null pointer error
    LED_OK,             // Operation successful
    LED_INVALID_PARAM,  // Invalid parameter error
    LED_NOK             // Operation failed
} LED_enuErrorStatus_t;

/* Function Prototypes */
LED_enuErrorStatus_t LED_vInit(void);
LED_enuErrorStatus_t LED_SetState(u8 LedNum, u8 State);

#endif /* _LED_H_ */