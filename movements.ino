#include "movements.h"
#include "helper/motor.h"

static void right(float x, float y) {
  digitalWrite(MOTOR_INPUT_A_2, LOW);
  digitalWrite(MOTOR_INPUT_B_2, LOW);
  analogWrite(MOTOR_INPUT_A_1, 255*x);
  analogWrite(MOTOR_INPUT_B_1, 255*y);
}

static void left(float x, float y) {  
  digitalWrite(MOTOR_INPUT_A_1, LOW);
  digitalWrite(MOTOR_INPUT_B_1, LOW);
  analogWrite(MOTOR_INPUT_A_2, 255*x);
  analogWrite(MOTOR_INPUT_B_2, 255*y);
}

void shakeHead(float x, float y) {
  if(x > 1) x = 1;
  if(y > 1) y = 1;
  left(x, y);
  delay(300);
  brake();
  delay(10);
  right(x, y);
  delay(500);
  brake();
  delay(10);
  left(x, y);
  delay(500);
  brake();
  right(x, y);
  delay(360);
  brake();
}

static void spinLeft(float x) {
  if(x > 1) x = 1;
  left(x, x);
  delay(1950);
  brake();
}

static void spinRight(float x) {
  if(x > 1) x = 1;
  right(x, x);
  delay(1970);
  brake();
}

void spin(float x) {
  spinLeft(x);
  spinRight(x);
}