#include "ch32v00x.h"
#include <uart_driver.h>

void led_init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef led;
    led.GPIO_Pin = GPIO_Pin_4;   // PD4
    led.GPIO_Speed = GPIO_Speed_50MHz;
    led.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &led);
}

void led_toggle()
{
    GPIOD->OUTDR ^= GPIO_Pin_4;  // PD4
}


int main(void)
{
    led_init();
    uart_init(9600);

    uart_send_string("UART Echo Ready\r\n");

    while(1)
    {
        char c = uart_receive_char();

        uart_send_string("RX: ");
        uart_send_char(c);
        uart_send_string("\r\n");

        uart_send_string("TX: ");
        uart_send_char(c);
        uart_send_string("\r\n");

        if(c == '1')
        {
            led_toggle();
            uart_send_string("LED Toggled\r\n");
        }
    }
}
