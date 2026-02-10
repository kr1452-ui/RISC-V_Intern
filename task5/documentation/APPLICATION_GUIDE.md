# Application Guide

## Application Behavior

1. System initializes LED GPIO and UART.
2. Prints "UART Echo Ready" on terminal.
3. Waits for user input from terminal.
4. Received character is echoed back with RX and TX labels.
5. If received character is '1', LED on PD4 toggles.

## Application Flow

```
Start
  ↓
UART Init
  ↓
Print Ready Message
  ↓
Wait for Character
  ↓
Echo Character
  ↓
If '1' → Toggle LED
  ↓
Repeat
```

## Timing Behavior

* UART functions operate in blocking (polling) mode.
* Application continuously waits for user input.

## Edge Case Handling

* Invalid characters are simply echoed back.
* System never crashes due to unexpected input.
