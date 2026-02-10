Task-4: Software PWM Multi-Channel LED Dimmer

VSDSquadron Mini – CH32V003 (RISC-V)

1. Project Overview

This project demonstrates software-based PWM (Pulse Width Modulation) on the VSDSquadron Mini board when hardware PWM channels are limited.

Multiple LEDs are dimmed using timer interrupts, and each LED has an independent duty cycle.

The goal of this task is to show multi-driver integration using:

GPIO driver

Timer driver

UART driver (integrated)

This project runs on real hardware and produces visible LED dimming.

2. Hardware Used

Board: VSDSquadron Mini

MCU: CH32V003F4U6 (RISC-V, 24 MHz)

Power: USB-C

LEDs: 2 external LEDs on breadboard

Resistors: 220Ω 

LED Connections
LED	MCU Pin
LED1	PD3
LED2	PD4

Wiring for each LED:

MCU GPIO → Resistor → LED → GND

3. Drivers Used
GPIO Driver

Initializes GPIO pins as output

Turns LEDs ON and OFF

No direct register access in main.c

Timer Driver

Uses TIM2 interrupt

Generates periodic interrupts

Implements software PWM logic

UART Driver

Implemented as a separate driver

Initialized for driver integration

Not used for live control in final demo (USB-TTL removed to avoid pin conflict)

4. Software PWM Implementation

Hardware PWM is not used.
PWM is generated in software using a timer interrupt.

PWM logic:

Timer interrupt every 100 µs

PWM counter runs from 0 to 99

One full PWM cycle = 10 ms

PWM frequency = 100 Hz

Core logic:

A 100 µs timer interrupt increments a counter from 0–99. Each LED compares this counter with its duty cycle to generate 100 Hz software PWM.

Example behavior:

if (pwm_counter < duty)
    LED ON
else
    LED OFF


Different duty values produce different brightness levels.

5. Application Flow (main.c)

main.c contains only application logic:

Initializes GPIO driver

Initializes timer driver

Enters infinite loop

PWM is fully handled inside timer ISR

There is no register-level code in main.c.

6. Demo Description

For the final demo:

USB-TTL is disconnected

Board is powered using USB-C

Two external LEDs are connected

Fixed duty cycles are used

LEDs show clearly different brightness levels

This demonstrates:

Timer interrupt working

Software PWM working

GPIO control working

Real hardware execution



7. How to Build and Flash

Open project in PlatformIO

Connect VSDSquadron Mini via USB-C

Run:

Clean

Build

Upload

Observe LED brightness on breadboard

8. Result

LEDs show different brightness levels

No flicker

Stable output

Task-4 requirements satisfied

Conclusion

This project successfully demonstrates software PWM using timer interrupts with clean driver abstraction.
It fulfills all Task-4 requirements for multi-driver integration on real hardware.
