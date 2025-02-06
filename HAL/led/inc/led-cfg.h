#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "STD_TYPES.h"

#define NUM_OF_LEDS 3
#define LED_1 0
#define LED_2 1
#define LED_3 2

#define ACTIVE_HIGH 0
#define ACTIVE_LOW 1

/* LED Configuration Structure */
typedef struct {
    u8 PORT;
    u8 PIN;
    u8 CONNECTION; // ACTIVE_HIGH or ACTIVE_LOW
} led_cfg_t;

/* Array of LED Configuration */
extern led_cfg_t led_arr[NUM_OF_LEDS];

#endif /* LED_CFG_H_ */