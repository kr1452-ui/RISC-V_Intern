# System Architecture

## High Level Block Diagram

```
          +-----------------------+
          |     Application       |
          |  (UART Echo + LED)   |
          +-----------+-----------+
                      |
              UART Driver Library
                      |
                 USART1 Hardware
                      |
               VSDSquadron Mini
```

## Design Separation

* **Driver Layer:** Handles all USART register configuration and communication.
* **Application Layer:** Implements logic for echo and LED control using only driver APIs.
* No hardware registers are accessed in the application.

## Data Flow

1. Character typed in terminal
2. Received by USART RX
3. `uart_receive_char()` fetches data
4. Application processes command
5. Data sent back using `uart_send_*` APIs

## Reason for This Architecture

This separation ensures:

* Reusability of UART driver in other projects
* Clean abstraction between hardware and logic
* Easier debugging and maintenance
