#include <Arduino.h>
#include <atomic>
#include "src/PAT_EventVariable.h"


//-----------------------------------------------------------------------------------
// Instantiate EventVariable objects
Event<int> shared_int_var(100);
Event<float> shared_float_var(50.0f);


//-----------------------------------------------------------------------------------
void setup() {

  Serial.begin(115200);
  // Wait for serial monitor to open
  delay(1000);

  // Set callback for integer variable
  shared_int_var.setOnChangeCallback([]() {
    log("shared_int_var = " + String(shared_int_var));
  });

  // Set callback for float variable
  shared_float_var.setOnChangeCallback([]() {
    log("shared_float_var = " + String(shared_float_var));
  });
}
//-----------------------------------------------------------------------------------
void loop() {
  if (shared_int_var == 10) {
    Serial.println("shared_var is equal to 10");
  }
  if (shared_int_var != 0) {
    Serial.println("shared_var is not equal to 0");
  }
  if (shared_int_var > 5) {
    Serial.println("shared_var is greater than 5");
  }
  if (shared_int_var >= 15) {
    Serial.println("shared_var is greater than or equal to 15");
  }
  if (shared_int_var < 20) {
    Serial.println("shared_var is less than 20");
  }
  if (shared_int_var <= 5) {
    Serial.println("shared_var is less than or equal to 5");
  }
//-----------------------------------------------------------------------------------
  // Demonstrate various operators
  shared_int_var++;      // Postfix increment
  ++shared_int_var;      // Prefix increment
  shared_int_var--;      // Postfix decrement
  --shared_int_var;      // Prefix decrement
  shared_int_var += 10;  // Compound assignment +=
  shared_int_var -= 5;   // Compound assignment -=
  shared_int_var *= 2;   // Compound assignment *=
  shared_int_var /= 3;   // Compound assignment /=
  shared_int_var %= 4;   // Compound assignment %=
  shared_int_var &= 5;   // Compound assignment &=
  shared_int_var |= 6;   // Compound assignment |=
  shared_int_var ^= 7;   // Compound assignment ^=
  shared_int_var <<= 2;  // Compound assignment <<=
  shared_int_var >>= 1;  // Compound assignment >>=

  //-----------------------------------------------------------------------------------
  // Demonstrate float operators
  shared_float_var += 2.5f;  // Compound assignment +=
  shared_float_var -= 1.0f;  // Compound assignment -=
  shared_float_var *= 1.5f;  // Compound assignment *=
  shared_float_var /= 2.0f;  // Compound assignment /=
  // End of loop }
  vTaskDelete(NULL);
}
