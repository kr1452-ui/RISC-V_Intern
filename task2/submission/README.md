# Task-2: VSDSquadron Mini Board Bring-Up, GPIO & UART Validation

## Overview
This task focuses on bringing up real hardware using the VSDSquadron Mini RISC-V board.  
The objective is to flash firmware on the board, validate UART communication, and verify GPIO pin control using a clean firmware architecture.

This task transitions from host-based development (Task-1) to actual hardware execution.

---

## Board Bring-Up & Firmware Flashing
- Firmware was successfully compiled and flashed onto the VSDSquadron Mini board.
- The board boots correctly after flashing.
- UART output is observed immediately after reset using a serial terminal.

---

## UART Validation
UART is used as the primary debug interface.

### UART Output Includes:
- Board Name: **VSDSquadron Mini**
- Firmware Version: **v1.0**
- Periodic counter message printed continuously

### Verification:
- UART output shows more than **10 consecutive readable lines**
- Output captured using a serial terminal (e.g., PuTTY / minicom)

---

## GPIO Pin Mapping & Validation
One GPIO pin was selected and verified on real hardware.

### GPIO Details:
- **Physical Pin Label:** (as printed on the board)
- **Firmware GPIO Number:** (as per datasheet mapping)

### Behavior:
- GPIO configured as OUTPUT
- Pin toggles periodically (LED blink / visible signal)

GPIO numbering strictly follows the board datasheet.

---

## Firmware Architecture
The firmware follows a layered structure:

- `main.c`  
  - Application logic only  
  - No direct hardware register access  

- `gpio.c / gpio.h`  
  - GPIO abstraction layer  
  - Functions used:
    - `gpio_init()`
    - `gpio_set()`
    - `gpio_clear()`
    - `gpio_toggle()`

This structure mirrors real-world embedded firmware design.

---

## Build & Flash Steps (Summary)
1. Compile firmware using RISC-V toolchain
2. Flash binary onto VSDSquadron Mini board
3. Connect UART via USB
4. Open serial terminal and reset board
5. Observe UART logs and GPIO behavior

---

## Evidence
All hardware execution proof (UART logs, GPIO toggling photos/videos) is provided in **submission.md**.

