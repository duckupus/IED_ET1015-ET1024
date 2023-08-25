#ifndef TARGET_SENSORS_H
#define TARGET_SENSORS_H

#define HIT_A_PIN 4
#define HIT_B_PIN 2

volatile unsigned int hit_a;
volatile unsigned int hit_b;
void setup_target_sensors();

#endif /* TARGET_SENSORS_H */