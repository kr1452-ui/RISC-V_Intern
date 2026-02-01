# RISC-V Embedded Firmware Internship

This repository contains the work I completed as part of my RISC-V Embedded Firmware Internship using the VSDSquadron Mini board.

During this internship, I learned how low-level embedded systems actually work by writing firmware directly using registers, without relying on high-level libraries. The tasks focused on understanding GPIO, UART communication, and building reusable peripheral driver libraries in a structured way.

The goal was not just to make things work, but to follow proper embedded firmware practices such as separating driver code from application code, testing on real hardware, and documenting the work clearly.

---

## What I Worked On

### Task 1 – GPIO Basics
- Learned how to configure GPIO pins using registers.
- Controlled LEDs and understood pin modes and clock configuration.

### Task 2 – UART Communication
- Configured UART (USART) on the board.
- Sent and received data using a USB-TTL adapter and PuTTY.
- Verified serial communication on real hardware.

### Task 3 – Peripheral Driver Library + Application
- Designed and implemented a reusable UART driver library.
- Built an application that uses the library for UART echo and LED control.
- Demonstrated command-based LED toggling using serial input.
- Structured the project to clearly separate library code and application code.

---

## Skills Learned

- Understanding microcontroller registers and peripherals
- GPIO configuration and control
- UART communication using polling
- Writing reusable embedded driver libraries
- Using PlatformIO and VSCode for embedded development
- Testing firmware on real hardware
- Proper project structure and documentation

---

## Hardware Used

- VSDSquadron Mini (CH32V003, RISC-V based)
- USB-TTL adapter
- External LED and resistor
- PuTTY serial terminal

---

## Repository Structure

Each task is organized in its own folder with source code, documentation, and evidence of hardware testing.

---

This internship helped me gain practical experience in embedded firmware development and understand how low-level drivers are written and used in real applications.
