#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_INPUT_A_1 9 //FWD A
#define MOTOR_INPUT_A_2 6 //REV A
#define MOTOR_INPUT_B_1 5 //FWD B
#define MOTOR_INPUT_B_2 3 //REV B

void setup_motor();
void brake();
void forward(float);
void backward(float);
void turnLeft(float);
void turnRight(float);
void forward_ctl(float, float);
void backward_ctl(float, float);

#endif /* MOTOR_H */