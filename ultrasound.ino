#include "helper/ultrasound.h"

void setup_ultrasound() {
  pinMode(ULTRASOUND_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRASOUND_ECHO_PIN, INPUT);
  digitalWrite(ULTRASOUND_TRIGGER_PIN, LOW);
}

long distanceUltra() {/* this returns the distance in CM */
  delayMicroseconds(2);
  digitalWrite(ULTRASOUND_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASOUND_TRIGGER_PIN, LOW);
  return (pulseIn(ULTRASOUND_ECHO_PIN, HIGH) / 58);
}
