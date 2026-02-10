# Demo Guide

## Flashing Steps

1. Connect VSDSquadron Mini via USB.
2. Run:

   ```
   pio run --target upload
   ```
3. Open PuTTY.

## PuTTY Settings

* Baud Rate: 9600
* Data Bits: 8
* Stop Bits: 1
* Parity: None
* Flow Control: None

## Demo Steps

1. Reset the board.
2. Observe: "UART Echo Ready"
3. Type any character → echoed back.
4. Type `1` → LED on PD4 toggles.
5. Observe "LED Toggled" message.

## Expected Observation

* RX and TX logs visible on terminal.
* Physical LED toggles on command.
