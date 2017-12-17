#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int sensorPin = A0;
const int baseAngle = 1020;

int baseLight;
int lightLevel;

void setup() {
  myServo.attach(servoPin);
  reset();
}

void loop() {
  lightLevel = analogRead(sensorPin);
  
  if (abs(baseLight - lightLevel) > 100) {
    stab();
  }

}

void reset() {
  baseLight = analogRead(sensorPin);
  myServo.write(baseAngle);
}

void stab() {
  int stabs = random(1, 6);
  while (stabs > 0) {
    myServo.write(0); // swing arm down
    delay(25);
    myServo.write(800 + random(-150, 150)); // swing arm up
    delay(25);
    stabs--;
  }
}



