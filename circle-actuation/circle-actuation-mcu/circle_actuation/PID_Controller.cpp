#include "PID_Controller.h"

PID_Controller::PID_Controller(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;

    prevError = 0.0;
    integral = 0.0;
}

double PID_Controller::calculate(const double currentState, const double setpoint) {
    double error = setpoint - currentState;
    double derivative = error - prevError;
    integral += error;

    double output = (kP * error) + (kI * integral) + (kD * derivative);
    return output;
}