# Task-3 Evidence: UART Driver Library + Application

## 1. UART Evidence

A screenshot of PuTTY showing UART communication with more than 10 lines:

* `UART Echo Ready`
* RX and TX logs for multiple characters
* `LED Toggled` messages when `'1'` is pressed

This proves UART initialization, transmit, and receive functionality.



## 2. Hardware Evidence

Photos attached showing:

1. Wiring between VSDSquadron Mini and USB-TTL (PD5↔RX, PD6↔TX, GND↔GND)
2. External LED connected to PD4 with resistor
3. LED ON state
4. LED OFF state after pressing `'1'`

This proves command-based GPIO control using UART input.



## 3. Explanation of Working

* The application calls only UART library APIs.
* UART library handles all hardware register configuration.
* The received character is echoed back using library functions.
* When `'1'` is received, the application toggles PD4 LED.
* Verified on real hardware using PuTTY and physical LED observation.

