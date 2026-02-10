#include "gpio_driver.h"
#include "timer_driver.h"

int main(void)
{
    gpio_init();
    timer_init_100us();

    while (1)
    {
        // PWM handled fully in timer ISR
    }
}
