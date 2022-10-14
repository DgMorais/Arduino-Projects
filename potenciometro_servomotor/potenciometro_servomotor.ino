#include <Servo.h>

const int pot = A3;
int leitura;

Servo servo_motor;

void setup() {
  pinMode(pot, INPUT);
  servo_motor.attach(8);
}

void loop() {
  leitura = analogRead(pot);
  leitura = map(leitura, 0, 1023, 10, 180);
  servo_motor.write(leitura);
  delay(100);
}
