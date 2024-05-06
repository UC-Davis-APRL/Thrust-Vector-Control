#include <Arduino.h>
#include <Servo.h>

#include "PID_Controller.h"
#include "Ereg_Controller.h"

int servoPin = 9;
Servo valveServo = Servo();

PID_Controller setpointController = PID_Controller(0, 0, 0);
Ereg_Controller eregController;

void setup() {
  valveServo.attach(servoPin);
  eregController = Ereg_Controller(setpointController, valveServo, 1);

  Serial.begin(9600);
}

void loop() {
  while (Serial.available() == 0);

  double a, b, c, pressureSetpoint;

  a = Serial.parseFloat();
  b = Serial.parseFloat();
  c = Serial.parseFloat();
  pressureSetpoint = Serial.parseFloat();

  eregController.setEnginePressure(a, b, c, pressureSetpoint, pressureSetpoint);
}