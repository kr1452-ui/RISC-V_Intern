#include "ch32v00x.h"
#include "led_driver.h"

void led_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef led;
    led.GPIO_Pin = GPIO_Pin_4;
    led.GPIO_Speed = GPIO_Speed_50MHz;
    led.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &led);
}

void led_toggle(void)
{
    GPIOD->OUTDR ^= GPIO_Pin_4;
}
