#include "led-cfg.h"
#include "mdio.h"

/* LED Configuration Array */
led_cfg_t led_arr[NUM_OF_LEDS] = {
    [LED_1] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN0, .CONNECTION = ACTIVE_HIGH},
    [LED_2] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN1, .CONNECTION = ACTIVE_HIGH},
    [LED_3] = {.PORT = MDIO_PORTA, .PIN = MDIO_PIN2, .CONNECTION = ACTIVE_HIGH}
};