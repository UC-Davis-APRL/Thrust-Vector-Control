#include <Arduino.h>

#include "PID_Controller.h"

PID_Controller::PID_Controller(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;

  derivativeTimeStart = 0;
  integralUpdateTimeStart = 0;
  
  integralStartError = 0.0;
  integralPrevError = 0.0;
  derivativePrevError = 0.0;
  integral = 0.0;
}

double PID_Controller::getP() {
  return kP;
}

double PID_Controller::getI() {
  return kI;
}

double PID_Controller::getD() {
  return kD;
}

void PID_Controller::setP(double P) {
  kP = P;
}

void PID_Controller::setI(double I) {
  kI = I;
}

void PID_Controller::setD(double D) {
  kD = D;
}

double PID_Controller::calculate(const double currentState, const double setpoint) {
  static int count = 0;
  double derivative = 0;

  double error = setpoint - currentState;

  if (count > 0) derivative = (error - derivativePrevError) / ((millis() - derivativeTimeStart) * 1000);
  
  switch (count % 3) {
    case 0:
      integralStartError = error;
      integralUpdateTimeStart = millis();
      break;
    
    case 1:
      integralPrevError = error;
      break;
    
    case 2:
      integral += ((millis() - integralUpdateTimeStart) / (6000.0)) * (integralStartError + (4 * integralPrevError) + error);
      break;
  }
  count++;
  derivativePrevError = error;
  derivativeTimeStart = millis();

  double output = (kP * error) + (kI * integral) + (kD * derivative);
  return output;
}