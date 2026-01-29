#ifndef GPIO_H
#define GPIO_H

#include <ch32v00x.h>

/* Initialize GPIO for LED */
void gpio_init(void);

/* Toggle LED GPIO */
void gpio_toggle(void);

#endif
