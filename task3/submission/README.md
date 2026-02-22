# Task-3: UART Driver Library + Application

VSDSquadron Mini — CH32V003

## Implemented Library

This project implements a reusable **UART driver library** for the CH32V003 microcontroller on the VSDSquadron Mini board.

The driver abstracts all USART hardware configuration and provides clean APIs for transmit and receive using polling mode.
All hardware interaction is implemented inside library files, while the application uses only library APIs.

---

## UART Library APIs

* **uart_init(uint32_t baudrate)**
  Initializes USART1 with the specified baud rate.

* **uart_send_char(char c)**
  Sends one character using blocking transmit.

* **uart_send_string(const char *str)**
  Sends a null-terminated string.

* **uart_receive_char(void)**
  Receives one character using polling.

---

## Additional Helper Library

A small LED driver is included to demonstrate command-based control.

APIs:

* **led_init()** — configure LED GPIO
* **led_toggle()** — toggle LED state

---

## Demo Application Description

The application demonstrates UART echo and command interaction:

* On startup, terminal shows **“UART Echo Ready”**
* Any typed character is received and echoed back
* UART logs display RX and TX activity
* Sending character **‘1’** toggles the LED
* Terminal prints **“LED Toggled”**

This validates UART transmit, receive, and command-based control using the driver.

---

## Hardware Connections

* PD5 → UART TX → USB-TTL RX
* PD6 → UART RX → USB-TTL TX
* Common GND
* External LED → PD4 via resistor

---

## Build and Flash

1. Open project in VSCode (PlatformIO)
2. Build project
3. Connect VSDSquadron Mini
4. Upload firmware

---

## UART Terminal Configuration

* Baud rate: 9600
* Data bits: 8
* Stop bits: 1
* Parity: None
* Flow control: None

---

## Project Structure

task3/submission/

* lib/ → uart_driver + led_driver
* app/ → main.c
* README.md
* evidence → evidence.md

---

## Summary

This project demonstrates a reusable UART driver library with a working application following strict firmware design rules:

* No register access inside main
* Hardware accessed only via libraries
* Clean API design
* Modular structure
