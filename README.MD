# Event Class for ESP32

The `Event` class template provides a thread-safe mechanism to manage and observe changes in a variable of type `T` in ESP32 projects. It is designed to ensure data integrity in environments where multiple tasks or threads may access the same variable simultaneously.

## Features

- **Thread Safety**: Utilizes `std::atomic` for atomic operations, ensuring that read-modify-write operations on the variable are executed atomically, preventing data inconsistencies in concurrent access scenarios.
  
- **Mutex Locking**: Uses `std::mutex` to implement locking mechanisms. This ensures that only one thread can modify the variable at a time, preventing data races and ensuring thread-safe access to shared resources.

- **Callback Mechanism**: Provides a callback function that can be set to execute whenever the variable changes. This allows users to react to changes in real-time, such as updating displays or triggering actions based on variable updates.

- **Operator Overloading**: Supports a range of operators (`=`, `+=`, `-=` etc.) to manipulate the encapsulated variable directly. This simplifies code and makes the class intuitive to use in Arduino sketches.

- **ESP32 Compatibility**: Specifically designed for ESP32 microcontroller boards, ensuring compatibility with the Arduino framework and ESP-IDF.

## Usage

1. **Include the Header File**

   Include the `Event` class header in your ESP32 Arduino sketch or library:

   ```cpp
   #include "Event.h"
