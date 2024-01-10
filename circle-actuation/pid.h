#ifndef PID_H
#define PID_H

typedef struct PID_struct {
    double kP;
    double kI;
    double kD;

    double prevError;
    double integral;
} PID_Controller;

void init(PID_Controller* pidControllerPtr);
double calculate(PID_Controller* pidControllerPtr, double currentState, double setpoint);

#endif