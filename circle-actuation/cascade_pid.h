#ifndef CASCADE_PID_H
#define CASCADE_PID_H

#include "pid.h"

typedef struct Cascaded_PID_struct {
    PID_Controller primary;
    PID_Controller secondary;
} Cascaded_PID_Controller;

void initCascadedController(Cascaded_PID_Controller* controller);
double calculateCascadedOutput(Cascaded_PID_Controller* controllerPtr, const double primarySetpoint, const double currentPrimaryState, const double currentSecondaryState);

#endif