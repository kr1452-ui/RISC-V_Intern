# Task-3: UART Driver Library + Application  
**Board:** VSDSquadron Mini (CH32V003 RISC-V)

---

## 📌 What was implemented?

For Task-3, I implemented a **UART Driver Library** and demonstrated its usage through a small application running on the VSDSquadron Mini board.

The goal was to create reusable UART APIs and build a working demo that proves UART transmit, receive, and command handling on real hardware.

All hardware-level register configuration is kept **inside the library**, and the application only calls library functions as required by the task rules.

---

## 🧩 UART Library APIs

| API | Purpose |
|-----|--------|
| `uart_init(uint32_t baudrate)` | Initializes USART1 on PD5 (TX) and PD6 (RX) |
| `uart_send_char(char c)` | Sends one character (blocking) |
| `uart_send_string(const char *str)` | Sends a string over UART |
| `uart_receive_char(void)` | Receives a character using polling |

These APIs are reusable and can be used in any future project involving UART communication.

---

## 🚀 Demo Application

The application demonstrates two main features:

### 1️⃣ UART Echo
- Any key typed in PuTTY is received by the board
- The same character is transmitted back
- RX and TX logs are clearly printed on the terminal

### 2️⃣ Command-based LED Control
- When the character `'1'` is received, an external LED connected to **PD4** toggles ON/OFF
- A message **"LED Toggled"** is printed on UART

This proves practical use of UART RX, TX, and command handling.

---

## 🔌 Hardware Connections

| VSDSquadron Pin | Connection |
|------------------|------------|
| PD5 (TX) | RX of USB-TTL |
| PD6 (RX) | TX of USB-TTL |
| GND | GND of USB-TTL |
| PD4 | LED → 330Ω → GND |

> Note: The onboard user LED could not be used because it shares PD6 with UART RX. Hence, PD4 was used for LED demonstration.

---

## 🛠️ How to Build and Flash

1. Open the project in VSCode using PlatformIO
2. Click **Build**
3. Connect the board using USB-C
4. Click **Upload**

---

## 💻 UART (PuTTY) Settings

| Setting | Value |
|----------|------|
| Baud Rate | 9600 |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |
| Flow Control | None |

After pressing reset, the terminal shows:

