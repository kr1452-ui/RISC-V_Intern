#include "gpio_driver.h"
#include "ch32v00x.h"

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;

    // PD3
    gpio.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOD, &gpio);

    // PD4
    gpio.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOD, &gpio);
}

void gpio_set_led(uint8_t led)
{
    if (led == 2)
        GPIO_SetBits(GPIOD, GPIO_Pin_3);
    else if (led == 3)
        GPIO_SetBits(GPIOD, GPIO_Pin_4);
}

void gpio_clear_led(uint8_t led)
{
    if (led == 2)
        GPIO_ResetBits(GPIOD, GPIO_Pin_3);
    else if (led == 3)
        GPIO_ResetBits(GPIOD, GPIO_Pin_4);
}
