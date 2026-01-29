#include "gpio.h"

void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIOD clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* Configure PD4 as push-pull output */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* Start with LED OFF */
    GPIO_ResetBits(GPIOD, GPIO_Pin_4);
}

void gpio_toggle(void)
{
    if (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_4))
    {
        GPIO_ResetBits(GPIOD, GPIO_Pin_4);
    }
    else
    {
        GPIO_SetBits(GPIOD, GPIO_Pin_4);
    }
}
