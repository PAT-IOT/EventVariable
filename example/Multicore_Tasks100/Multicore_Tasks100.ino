#include <Arduino.h>
#include <atomic>
#include "src/PAT_EventVariable.h"

// Instantiate Event object for int
Event<int> shared_var(0);
SemaphoreHandle_t mutex;
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Task function to increment shared variables
void incTask(void* parameters) {
  while (1) {
    xSemaphoreTake(mutex, portMAX_DELAY);
    //---------------------------------------------------------------
    if (shared_var < 100) shared_var++;
    else vTaskDelete(NULL);
    log(shared_var);  // print data of shared_var in serial monitor
    //---------------------------------------------------------------
    xSemaphoreGive(mutex);
    vTaskDelay(random(10, 100) / portTICK_PERIOD_MS);
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  vTaskDelay(500 / portTICK_PERIOD_MS);
  // -- -- -- -- -- -- -- --
  mutex = xSemaphoreCreateMutex();
  shared_var.setOnChangeCallback([]() {
    log("shared_var is changed= " + String(shared_var));
  });
  // -- -- -- -- -- -- -- --
  Serial.println("---Start 40 number multi core task---");

  for (int i = 0; i < 25; i++) {
    String taskCore0 = "core0(task" + String(i) + ") ";
    String taskCore1 = "core1(task" + String(i) + ") ";

    xTaskCreatePinnedToCore(incTask, taskCore0.c_str(), 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(incTask, taskCore1.c_str(), 4096, NULL, 1, NULL, 1);
  }
  vTaskDelete(NULL);
}
void loop() {
  // This code will never be reached due to vTaskDelete in setup()
}
