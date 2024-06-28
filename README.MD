# Event Class for Arduino

The `Event` class template provides a thread-safe mechanism to manage and observe changes in a variable of type `T` in Arduino projects. It utilizes atomic operations and mutex locking to ensure data integrity across concurrent tasks or threads.

## Features

- **Thread Safety**: Uses `std::atomic` for atomic operations and `std::mutex` for locking to prevent data race conditions.
- **Callback Mechanism**: Allows setting a callback function to be invoked whenever the variable changes.
- **Operator Overloading**: Supports various operators (`=`, `+=`, `-=` etc.) for intuitive variable manipulation.
- **Arduino Compatibility**: Designed for compatibility with Arduino environments (`Arduino.h` included).

## Usage

1. **Include the Header File**

   Include the `Event` class header in your Arduino sketch or library:

   ```cpp
   #include "Event.h"

