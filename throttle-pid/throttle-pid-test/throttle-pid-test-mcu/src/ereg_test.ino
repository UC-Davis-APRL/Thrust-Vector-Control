#include <Arduino.h>
#include <Servo.h>

#include "PID_Controller.h"
#include "Ereg_Controller.h"

int servoPin = 9;
Servo valveServo = Servo();

PID_Controller setpointController = PID_Controller(0, 0, 0);
Ereg_Controller eregController = Ereg_Controller(setpointController, valveServo, 1);

void setup() {
  valveServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    double a, fluidDensity, tankPressure, pressureSetpoint;

    a = Serial.parseFloat();
    fluidDensity = Serial.parseFloat();
    tankPressure = Serial.parseFloat();
    pressureSetpoint = Serial.parseFloat();

    eregController.setEnginePressure(a, fluidDensity, tankPressure, pressureSetpoint, pressureSetpoint);

    Serial.print(a);
    Serial.print(" ");
    Serial.print(fluidDensity);
    Serial.print(" ");
    Serial.print(tankPressure);
    Serial.print(" ");
    Serial.println(pressureSetpoint);
  }
}