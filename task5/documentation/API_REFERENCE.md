# UART Driver API Reference

## 1. uart_init

```
void uart_init(uint32_t baudrate);
```

**Purpose:**
Initializes USART1 peripheral for serial communication.

**Parameters:**

* `baudrate` – Communication speed in bits per second (e.g., 9600)

**Returns:**
None

**Notes / Constraints:**

* Uses PD5 as TX and PD6 as RX
* Configured for 8N1 format
* Polling mode is used

**Example Usage:**

```
uart_init(9600);
```

---

## 2. uart_send_char

```
void uart_send_char(char c);
```

**Purpose:**
Transmits a single character over UART in blocking mode.

**Parameters:**

* `c` – Character to transmit

**Returns:**
None

**Notes:**

* Waits until TX buffer is empty before sending

**Example:**

```
uart_send_char('A');
```

---

## 3. uart_send_string

```
void uart_send_string(const char *str);
```

**Purpose:**
Sends a null-terminated string over UART.

**Parameters:**

* `str` – Pointer to string

**Returns:**
None

**Example:**

```
uart_send_string("Hello\r\n");
```

---

## 4. uart_receive_char

```
char uart_receive_char(void);
```

**Purpose:**
Receives one character using polling.

**Returns:**

* Received character

**Notes:**

* Function blocks until data is received

**Example:**

```
char c = uart_receive_char();
```
