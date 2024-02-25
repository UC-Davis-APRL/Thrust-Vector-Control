#ifndef EREG_PID_H
#define EREG_PID_H

#include "pid.h"

typedef struct Ereg_PID_struct {
    double specificGravity;
    double ullageVolumeThreshold;

    PID_Controller primary;
    PID_Controller secondary;
} Ereg_PID_Controller;

typedef enum Ereg_Type {
    KERO, LOX
} Ereg_Type_t;

void initEregController(Ereg_PID_Controller* controllerPtr, Ereg_Type_t eregType);
void updateGains(Ereg_PID_Controller* controllerPtr);
double calculateValveActuation(Ereg_PID_Controller* controllerPtr,
                               const double desiredPressureDrop,
                               const double pressureSetpoint,
                               const double currentPressure,
                               const double currentValveAngle);

#endif