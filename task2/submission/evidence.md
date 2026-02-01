# Task-2 Evidence: GPIO & UART Validation

## 1. UART Evidence

### Description
After flashing the firmware, UART output is observed on reset.  
The output includes board name, firmware version, and a continuously increasing counter.

### Proof
- Screenshot showing 10+ UART lines
- Video recording showing live UART output


<img width="421" height="311" alt="output terminal" src="https://github.com/user-attachments/assets/1f06fd3c-2c5b-49f3-b2c0-4aa4ee7894b1" />

https://github.com/user-attachments/assets/c63d4a49-6110-4bec-b166-22b446a7fbdc

---

## 2. GPIO Evidence

### GPIO Details
- Physical Pin Label: __PD4________
- Firmware GPIO Number: _______GPIO_PIN_4___

### Description
The selected GPIO pin is configured as OUTPUT and toggles periodically.  
The behavior is verified visually using an LED / probe.

### Proof
- Photo showing the board and connected pin
- Video showing GPIO toggling


![LED ](https://github.com/user-attachments/assets/0f15af4e-5c58-41ce-8433-e8e64e7201e4)
![Setup proof](https://github.com/user-attachments/assets/16ab13b7-b57a-426c-b46d-c5974595f674)


---

## 3. Verification Summary
- Firmware flashed successfully
- UART output confirmed after reset
- GPIO pin behavior matches firmware logic
- GPIO number matches datasheet mapping
