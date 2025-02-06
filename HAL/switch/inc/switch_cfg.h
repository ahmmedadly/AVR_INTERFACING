#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "STD_TYPES.h"

#define NUM_OF_SWITCHES 3
#define SWITCH_1 0
#define SWITCH_2 1
#define SWITCH_3 2

#define PULL_UP 0
#define PULL_DOWN 1

/* Error Status Type */
typedef enum {
    SWITCH_NULL_PTR,       // Null pointer error
    SWITCH_OK,             // Operation successful
    SWITCH_INVALID_PARAM,  // Invalid parameter error
    SWITCH_NOK             // Operation failed
} SWITCH_enuErrorStatus_t;

/* Switch Configuration Structure */
typedef struct {
    u8 PORT;
    u8 PIN;
    u8 CONNECTION; // PULL_UP or PULL_DOWN
} Switch_Cfg_t;

/* Array of Switch Configurations */
extern Switch_Cfg_t switch_arr[NUM_OF_SWITCHES];

#endif /* SWITCH_CFG_H_ */