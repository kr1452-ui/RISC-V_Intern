#include "uart_driver.h"
#include "led_driver.h"

int main(void)
{
    uart_init(9600);
    led_init();

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
