

# Task-4: Software PWM Multi-Channel LED Dimmer

**VSDSquadron Mini (CH32V003F4U6)**

---

## 1. Project Overview

This project implements a **software-based PWM (Pulse Width Modulation) LED dimmer** on the **VSDSquadron Mini** board.

Since the microcontroller has limited hardware PWM channels, PWM is generated **in software** using a **timer interrupt**. Multiple LEDs are controlled independently using GPIO pins.

This project is developed as part of **Task-4: Multi-Driver Integration**.

---

## 2. Objective

The main objectives of Task-4 are:

* Integrate multiple drivers into a single working application
* Run the application on **real hardware**
* Demonstrate timer interrupts, GPIO control, and clean driver separation

This project demonstrates:

* GPIO driver usage
* Timer driver usage
* Software PWM logic
* Real hardware LED dimming

---

## 3. Hardware Used

* **Board**: VSDSquadron Mini
* **MCU**: CH32V003F4U6 (RISC-V, 24 MHz)
* **Power Supply**: USB-C

### External LEDs

| LED  | GPIO Pin |
| ---- | -------- |
| LED1 | PD3      |
| LED2 | PD4      |

* **Resistors**: 220Ω 
* **Breadboard**

### LED Connection

Each LED is connected as:

```
MCU GPIO → Resistor → LED → GND
```

---

## 4. Software PWM Explanation

Hardware PWM is not used in this project. Instead, PWM is generated using a **timer interrupt**.

### PWM Logic

* Timer interrupt interval: **100 µs**
* PWM counter range: **0 to 99**
* One full PWM cycle = `100 × 100 µs = 10 ms`
* PWM frequency = **100 Hz**

For each LED, the logic is:

```c
if (pwm_counter < duty)
    LED ON;
else
    LED OFF;
```

### Important Explanation Line (Task-4 Requirement)

> A 100 µs timer interrupt increments a counter from 0–99. Each LED compares this counter with its duty cycle to generate 100 Hz software PWM.

---

## 5. Drivers Used

### GPIO Driver

* Initializes GPIO pins (PD3, PD4) as output pins
* Provides APIs to turn LEDs ON and OFF

### Timer Driver

* Configures TIM2 to generate a 100 µs interrupt
* Maintains a PWM counter
* Generates software PWM inside the interrupt service routine (ISR)

### UART Driver

* Implemented as part of driver integration
* Not used for live control in the final demo
* Included to satisfy the multi-driver integration requirement

---

## 6. Folder Structure (Task-4 Compliant)

```
task4/
└── submission/
    ├── app/
    │   └── main.c
    ├── lib/
    │   ├── gpio_driver.c
    │   ├── gpio_driver.h
    │   ├── timer_driver.c
    │   ├── timer_driver.h
    │   ├── uart_driver.c
    │   ├── uart_driver.h
    ├── README.md
    └── evidence.md
```

---

## 7. `main.c` Responsibility

`main.c` contains **only application-level logic**, as required by Task-4:

* Driver initialization
* No direct register access
* No hardware configuration

PWM generation is fully handled inside the **timer driver ISR**.

---

## 8. Demo Description

* Board powered using **USB-C**
* Two external LEDs connected to **PD3 and PD4**
* LEDs glow at **different brightness levels**
* Visible brightness difference confirms software PWM operation

USB-TTL is **not connected** during the final demo to avoid pin conflicts.

---

## 9. How to Build and Upload

Using **PlatformIO**:

1. Open the project
2. Clean the build
3. Build the project
4. Upload the firmware
5. Observe LED brightness on the hardware

---

## 10. Result

* Software PWM works correctly
* Timer interrupt operation verified
* GPIO control verified
* Multi-driver integration achieved
* All Task-4 requirements satisfied

---

## 11. Conclusion

This project successfully demonstrates a **software-based PWM LED dimmer** implemented using timer interrupts on real hardware.


---

