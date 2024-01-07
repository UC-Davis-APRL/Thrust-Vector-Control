#ifndef PID_H
#define PID_H

typedef struct PID_struct {
    double kP;
    double kI;
    double kD;

    double prevError = 0;
    double integral = 0;
} PID_Controller;

double calculate(PID_Controller* pidControllerPtr, double currentState, double setpoint);

#endif