#include <Arduino.h>

// put function declarations here:

void setup() {
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
  // delay in ms
  delay(1000);
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

// put function definitions here: