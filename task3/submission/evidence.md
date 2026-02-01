# Task-3 Evidence: UART Driver Library and Application

## UART Evidence

A PuTTY serial terminal was used to test the UART communication.

After resetting the board, the message "UART Echo Ready" is displayed. When characters are typed in PuTTY, the board receives them and sends them back. The terminal shows clear logs of both received (RX) and transmitted (TX) characters.

More than 10 lines of UART logs are visible in the screenshot, showing continuous communication and the message "LED Toggled" whenever the character '1' is sent.

<img width="959" height="511" alt="task3 terminal pic" src="https://github.com/user-attachments/assets/2986888f-bf65-4dec-bbb7-13c5a6fee355" />


This proves that UART initialization, transmit, and receive are working correctly.

---

## Hardware Evidence

Photos are attached showing:

- The wiring between the VSDSquadron Mini and the USB-TTL adapter.
- The external LED connected to PD4 through a resistor.
- The LED in ON state.
- The LED in OFF state after sending the command '1'.

  ![task3 pic2](https://github.com/user-attachments/assets/cab01cdf-55b8-4e8f-94a5-82238529874a)
  ![task3 pic](https://github.com/user-attachments/assets/9778cfe0-3656-4085-b1a1-19ad6ef5bfdf)


This proves that UART input is being used to control a GPIO output on real hardware.



## Explanation of How the Application Uses the Library

The application does not directly configure any hardware registers. It only calls the UART library APIs.

The UART library handles all USART configuration and data transfer. The application receives a character using the library function and sends it back using another library function.

When the character '1' is received, the application toggles the LED connected to PD4 and prints a message to the serial terminal.

---

## What Was Verified on Hardware

The following were verified physically on the board:

- UART communication between the board and PuTTY.
- Correct echo of typed characters.
- Command-based control of an external LED using UART input.
- Clear separation between driver code and application code.
