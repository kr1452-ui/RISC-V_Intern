# UART Driver Library and Echo Application

**Target Board:** VSDSquadron Mini (CH32V003 – RISC-V)

## Project Summary

This project implements a reusable UART driver library for the CH32V003 microcontroller and demonstrates its usage through a UART echo and command-based LED control application. The driver abstracts all low-level USART register configuration and exposes simple APIs for transmitting and receiving data using polling mode.

The application uses this library to create an interactive UART session where received characters are echoed back to the terminal, and specific commands control an external LED.

## Supported Peripheral Driver

* UART (USART1) Driver using polling mode

## Hardware Used

* VSDSquadron Mini board
* USB-TTL adapter
* External LED on PD4 with 220Ω resistor

## Project Structure

```
lib/
 └── led_driver.c
 └── led_driver.h
 └── uart_driver.c
 └── uart_driver.h

app/
 └── main.c
```

## Quick Start (Build and Flash)

```
pio run
pio run --target upload
open PuTTY at 9600 baud
reset the board
start typing characters
```
