#include <Servo.h>

Servo servo_motor;

void setup() {
  servo_motor.attach(8);
  servo_motor.write(160);
}

void loop() {
  
}
