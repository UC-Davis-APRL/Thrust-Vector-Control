#ifndef EREG_PID_H
#define EREG_PID_H

#include "pid.h"

typedef struct Ereg_PID_struct {
    double ullageVolumeThreshold;

    PID_Controller primary;
    PID_Controller secondary;
} Ereg_PID_Controller;

void initEregController(Ereg_PID_Controller* controllerPtr);
void updateGains(Ereg_PID_Controller* controllerPtr, double currentUllageVolume);
double calculateValveActuation(Ereg_PID_Controller* controllerPtr,
                               const double a,
                               const double b,
                               const double c,
                               const double pressureSetpoint,
                               const double currentPressure,
                               const double currentValveAngle);

#endif