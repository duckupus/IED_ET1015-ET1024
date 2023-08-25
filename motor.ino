#include "helper/motor.h"

void setup_motor() {
  pinMode(MOTOR_INPUT_A_1, OUTPUT);
  pinMode(MOTOR_INPUT_A_2, OUTPUT);
  pinMode(MOTOR_INPUT_B_1, OUTPUT);
  pinMode(MOTOR_INPUT_B_2, OUTPUT);
}

void backward(float x) { /* float number */
  if(x > 1) x = 1;
  digitalWrite(MOTOR_INPUT_A_2, LOW);
  digitalWrite(MOTOR_INPUT_B_1, LOW);
  analogWrite(MOTOR_INPUT_A_1, 255*x);
  analogWrite(MOTOR_INPUT_B_2, 255*x);
}

void forward(float x) { /* float number */
  if(x > 1) x = 1;
  digitalWrite(MOTOR_INPUT_A_1, LOW);
  digitalWrite(MOTOR_INPUT_B_2, LOW);
  analogWrite(MOTOR_INPUT_A_2, 255*x);
  analogWrite(MOTOR_INPUT_B_1, 255*x);
}

void turnLeft(float x) {
  if(x > 1) x = 1;
  digitalWrite(MOTOR_INPUT_A_1, LOW);
  analogWrite(MOTOR_INPUT_A_2, 255*x);
  digitalWrite(MOTOR_INPUT_B_1, LOW);
  analogWrite(MOTOR_INPUT_B_2, 255*x);
}

void turnRight(float x) {
  if(x > 1) x = 1;
  digitalWrite(MOTOR_INPUT_A_2, LOW);
  analogWrite(MOTOR_INPUT_A_1, 255*x);
  digitalWrite(MOTOR_INPUT_B_2, LOW);
  analogWrite(MOTOR_INPUT_B_1, 255*x);
}

void brake() { /* stops the car */
  digitalWrite(MOTOR_INPUT_A_1, LOW);
  digitalWrite(MOTOR_INPUT_A_2, LOW);
  digitalWrite(MOTOR_INPUT_B_1, LOW);
  digitalWrite(MOTOR_INPUT_B_2, LOW);
}

void forward_ctl(float x, float y) {
  if(x > 1) x = 1;
  if(y > 1) y = 1;
  digitalWrite(MOTOR_INPUT_A_1, LOW);
  digitalWrite(MOTOR_INPUT_B_2, LOW);
  analogWrite(MOTOR_INPUT_A_2, 255*x);
  analogWrite(MOTOR_INPUT_B_1, 255*y);
}

void backward_ctl(float x, float y) {
  if(x > 1) x = 1;
  if(y > 1) y = 1;
  digitalWrite(MOTOR_INPUT_A_2, LOW);
  digitalWrite(MOTOR_INPUT_B_1, LOW);
  analogWrite(MOTOR_INPUT_A_1, 255*x);
  analogWrite(MOTOR_INPUT_B_2, 255*y);
}

