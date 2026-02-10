#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>

void gpio_init(void);
void gpio_set_led(uint8_t led);
void gpio_clear_led(uint8_t led);

#endif
