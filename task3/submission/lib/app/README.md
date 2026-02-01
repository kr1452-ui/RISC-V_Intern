Task-3: UART Driver Library + Application (VSDSquadron Mini)
Implemented Library

UART Driver Library for CH32V003 (VSDSquadron Mini)

This library provides reusable APIs to initialize UART, transmit data, and receive data using polling mode.
All hardware register interactions are encapsulated inside the library as required.

UART Library APIs
API	Description
void uart_init(uint32_t baudrate);	Initializes USART1 on PD5 (TX) and PD6 (RX)
void uart_send_char(char c);	Sends one character (blocking)
void uart_send_string(const char *str);	Sends a string over UART
char uart_receive_char(void);	Receives one character using polling

All register configurations and USART setup are done only inside the library.

Demo Application Description

The application demonstrates the use of the UART library through:

UART Echo:

Any character typed in PuTTY is received and sent back.

RX and TX logs are printed.

Command-based LED Control:

When the character '1' is received, an external LED connected to PD4 toggles ON/OFF.

UART prints LED Toggled message.

This shows practical use of UART RX, TX and command handling.

Hardware Connections
VSDSquadron Pin	Connection
PD5 (TX)	RX of USB-TTL
PD6 (RX)	TX of USB-TTL
GND	GND of USB-TTL
PD4	External LED → 330Ω → GND

Note: On-board user LED (PD6) cannot be used because it shares the UART RX pin.

How to Build and Flash

Open project in VSCode with PlatformIO

Click Build

Connect board using USB-C

Click Upload

UART Configuration (PuTTY)
Setting	Value
Baud rate	9600
Data bits	8
Stop bits	1
Parity	None
Flow control	None

After reset, PuTTY shows:

UART Echo Ready
