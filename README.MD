# Event Class Template Documentation

## Summary
The `Event` class template provides a robust and thread-safe solution for monitoring and managing variable changes in ESP32 projects. With features like operator overloading, mutex locking, and callback mechanisms, it ensures data integrity, thread safety, and seamless integration with ESP32 applications.

## Features
- **Thread Safety**: Uses `std::atomic` for atomic operations and `std::mutex` for thread safety.
- **Callback Mechanism**: Allows defining callback functions to respond to variable changes.
- **Operator Overloading**: Enables various operators for direct variable manipulation.
- **ESP32 Compatibility**: Designed and tested for compatibility with ESP32 microcontrollers.

## Usage
1. **Initialization**: Create an instance of the `Event` class with an initial value.
   
2. **Operations**:
   - Perform operations like incrementing, decrementing, compound assignments, and comparisons.
   - Set a custom `onChangeCallback` function to execute actions on value changes.

3. **Integration**: Include the `Event` class in your ESP32 Arduino sketch.

## Code Snippet Explanation
- Provides operator overloads for arithmetic and logical operations.
- Ensures thread safety using mutex locking and atomic operations.
- Executes the callback function upon variable changes.
- Supports relational and logical comparison operators for value comparisons.

## Example Usage
```cpp
#include "Event.h"

// Initialize an Event object with an initial value of 50.0 (float)
Event<float> f(50.0);

// Initialize an Event object with an initial value of 50 (integer)
Event<int> i(50);

void setup() {
  Serial.begin(9600);

  // Print the initial value of float event
  Serial.print("Initial float value: ");
  Serial.println(f);

  // Print the initial value of integer event
  Serial.print("Initial integer value: ");
  Serial.println(i);

  // Define a callback function for float event to print a message on value change
  f.setOnChangeCallback([](){
    Serial.println("Float value has changed! New value: " + String(f));
  });

  // Define a callback function for integer event to print a message on value change
  i.setOnChangeCallback([](){
    Serial.println("Integer value has changed! New value: " + String(i));
  });

  // Increase the float value and print the updated value
  f += 25.0;
  Serial.print("Updated float value: ");
  Serial.println(f);

  // Decrease the integer value and print the updated value
  i -= 10;
  Serial.print("Updated integer value: ");
  Serial.println(i);
}
