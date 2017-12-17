#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int sensorPin = A0;
const int baseAngle = 1020;
const int baseLight;

int lightLevel;

void setup() {
  myServo.attach(servoPin);
  reset();
}

void loop() {


}

void reset() {
  baseLight = analogRead(sensorPin);
  myServo.write(baseAngle);
}
