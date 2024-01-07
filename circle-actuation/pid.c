#include "pid.h"

double calculate(PID_Controller* pidControllerPtr, double currentState, double setpoint) {
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