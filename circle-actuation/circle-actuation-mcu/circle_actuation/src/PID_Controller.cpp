#include <Arduino.h>

#include "PID_Controller.h"

PID_Controller::PID_Controller(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;

  timeStart = 0;
  
  startError = 0.0;
  prevError = 0.0;
  integral = 0.0;
}

double PID_Controller::calculate(const double currentState, const double setpoint) {
  static int count = 0;

  double error = setpoint - currentState;
  double derivative = error - prevError;
  
  switch (count % 3) {
    case 0:
      startError = error;
      timeStart = millis();
      break;
    
    case 1:
      prevError = error;
      break;
    
    case 2:
      integral += ((millis() - timeStart) / (6000.0)) * (startError + (4 * prevError) + error);
      break;
  }
  count++;

  double output = (kP * error) + (kI * integral) + (kD * derivative);
  return output;
}