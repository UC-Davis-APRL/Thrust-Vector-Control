#include <math.h>

#include "ereg_pid.h"

#define M_PI 3.1415

void initEregController(Ereg_PID_Controller* controllerPtr, Ereg_Type_t eregType) {
    PID_Controller primary;
    PID_Controller secondary;

    switch (eregType) {
        case KERO:
            controllerPtr->specificGravity = 0.82;
            break;
        case LOX:
            controllerPtr->specificGravity = 1.14;
            break;
    }

    init(&primary);
    init(&secondary);

    controllerPtr->primary = primary;
    controllerPtr->secondary = secondary;
}

void updateGains(Ereg_PID_Controller* controllerPtr, double currentUllageVolume) {
    double multiplier = currentUllageVolume / controllerPtr->ullageVolumeThreshold;

    if (multiplier < 1) {
        PID_Controller primary = controllerPtr->primary;

        primary.kP *= multiplier;
        primary.kI *= multiplier;
        primary.kD *= multiplier;

        controllerPtr->primary = primary;
    }
}

double calculateValveActuation(Ereg_PID_Controller* controllerPtr,
                               const double pressureSetpoint,
                               const double currentPressure,
                               const double currentValveAngle) {
    PID_Controller primary = controllerPtr->primary;
    PID_Controller secondary = controllerPtr->secondary;

    double desiredFlowRate = 1;
    double desiredCv = desiredFlowRate * sqrt(controllerPtr->specificGravity / fabs(currentPressure - pressureSetpoint));
    double valveFeedforward = (7.84033 + ((-0.7624865 - 7.84033) / (1 + pow(desiredCv / 7243.604, 0.1969319)))) * M_PI / 2.0;
    double valveSetpoint = calculate(&primary, currentPressure, pressureSetpoint) + valveFeedforward;

    double valveActuation = calculate(&secondary, currentValveAngle, valveSetpoint);

    controllerPtr->primary = primary;
    controllerPtr->secondary = secondary;

    return valveActuation;
}