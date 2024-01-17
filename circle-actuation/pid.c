#include "pid.h"

void init(PID_Controller* pidControllerPtr) {
    pidControllerPtr->prevError = 0.0;
    pidControllerPtr->integral = 0.0;
}

double calculate(PID_Controller* pidControllerPtr, const double currentState, const double setpoint) {
    double kP = pidControllerPtr->kP;
    double kI = pidControllerPtr->kI;
    double kD = pidControllerPtr->kD;
    double integral = pidControllerPtr->integral;
    double prevError = pidControllerPtr->prevError;

    double error = setpoint - currentState;

    integral += error;
    pidControllerPtr->integral = integral;

    double derivative = error - prevError;
    pidControllerPtr->prevError = error;

    double controllerOutput = (kP * error) + (kI * integral) + (kD * derivative);
    return controllerOutput;
}