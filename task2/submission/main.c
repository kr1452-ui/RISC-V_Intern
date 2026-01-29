#include <ch32v00x.h>
#include "gpio.h"
#include "uart.h"

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 8000; i++)
        __NOP();
}

int main(void)
{
    uint32_t count = 0;

    SystemCoreClockUpdate();
    USART1_Init();
    gpio_init();

    /* ⭐ CRITICAL: wait for terminal */
    delay_ms(2000);

    /* Flush junk characters */
    USART1_SendString("\r\n\r\n\r\n");

    /* Startup banner */
    USART1_SendString("=================================\r\n");
    USART1_SendString(" Board    : VSDSquadron Mini\r\n");
    USART1_SendString(" Firmware : Task-2 GPIO + UART\r\n");
    USART1_SendString("=================================\r\n");

    while (1)
    {
        USART1_SendString("GPIO TOGGLE | Count = ");
        USART1_SendNumber(count);
        USART1_SendString("\r\n");

        gpio_toggle();
        count++;
        delay_ms(500);
    }
}
