#include "uart.h"

void USART1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(
        RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1,
        ENABLE
    );

    /* PD5 -> USART1 TX */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_Mode = USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}

void USART1_SendChar(char c)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, c);
}

void USART1_SendString(const char *str)
{
    while (*str)
        USART1_SendChar(*str++);
}

void USART1_SendNumber(uint32_t num)
{
    char buf[10];
    int i = 0;

    if (num == 0)
    {
        USART1_SendChar('0');
        return;
    }

    while (num)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
        USART1_SendChar(buf[i]);
}
