#include "helper/target_sensors.h"

/*
  this program generally follows this guide: https://thewanderingengineer.com/2014/08/11/arduino-pin-change-interrupts/
  
*/

void setup_target_sensors() {
  pinMode(HIT_A_PIN, INPUT_PULLUP);
  pinMode(HIT_B_PIN, INPUT_PULLUP);
  hit_a = 0;
  hit_b = 0; 
  PCICR |= B00000100; // Enable interrupts on PD port (D0 to D7)
  PCMSK2 |= B00010100; // Trigger interrupts on pins D2 and D4
}


volatile bool StateA_Prev = 0, StateB_Prev = 0; //initialize to 0

ISR(PCINT2_vect) {
  bool StateA = digitalRead(HIT_A_PIN);
  bool StateB = digitalRead(HIT_B_PIN);
  if(StateA_Prev > StateA) {
    hit_a = !hit_a;
  } else if(StateB_Prev > StateB) {
    hit_b = !hit_b;
  }
  StateA_Prev = StateA;
  StateB_Prev = StateB;
}