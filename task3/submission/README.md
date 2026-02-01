# Task-3: UART Driver Library and Application – VSDSquadron Mini

## Implemented Library

For Task-3, I implemented a reusable UART driver library for the CH32V003 microcontroller on the VSDSquadron Mini board.

This library handles all USART hardware configuration and provides simple APIs for transmitting and receiving data using polling mode. All register-level configuration is done inside the library as required by the task rules. The application code does not access any registers directly.

---

## UART Library APIs

The following APIs were designed and implemented:

- uart_init(uint32_t baudrate)  
  Initializes USART1 with the given baud rate using PD5 as TX and PD6 as RX.

- uart_send_char(char c)  
  Sends a single character over UART in blocking mode.

- uart_send_string(const char *str)  
  Sends a string of characters over UART.

- uart_receive_char(void)  
  Receives a single character using polling.

These functions make the UART driver reusable for other applications.

---

## Demo Application Description

A small application was developed to demonstrate the use of the UART library.

When the board is powered and connected to PuTTY:

- The message "UART Echo Ready" is displayed.
- Any character typed in PuTTY is received by the board and sent back.
- The UART log clearly shows both received and transmitted characters.
- When the character '1' is sent from PuTTY, an external LED connected to PD4 toggles ON and OFF.
- A message "LED Toggled" is printed on the serial terminal.

This demonstrates UART receive, UART transmit, and command-based control using the driver library.

---

## Hardware Connections

The following connections were used for testing:

- PD5 (TX) of VSDSquadron Mini connected to RX of USB-TTL adapter
- PD6 (RX) of VSDSquadron Mini connected to TX of USB-TTL adapter
- GND connected between both devices
- External LED connected to PD4 through a 330 ohm resistor to GND

The onboard user LED could not be used because it shares the same pin as UART RX (PD6).

---

## How to Build and Flash the Firmware

1. Open the project in VSCode using PlatformIO.
2. Click Build to compile the project.
3. Connect the VSDSquadron Mini board using USB-C.
4. Click Upload to flash the firmware onto the board.

---

## UART Configuration in PuTTY

PuTTY was configured with the following settings:

- Baud rate: 9600
- Data bits: 8
- Stop bits: 1
- Parity: None
- Flow control: None

After resetting the board, the UART output appears in PuTTY.

---

## Project Structure

The project is organized so that the UART driver and the application code are clearly separated:

- The UART driver files are inside the `lib/uart_driver` folder.
- The application logic is inside `src/main.c`.

This structure follows the Task-3 requirement of separating library code from application code.
