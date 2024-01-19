#include "cascade_pid.h"

void initCascadedController(Cascaded_PID_Controller* controllerPtr) {
    PID_Controller primary;
    PID_Controller secondary;

    init(&primary);
    init(&secondary);

    controllerPtr->primary = primary;
    controllerPtr->secondary = secondary;
}

void updateGains(Cascaded_PID_Controller* controllerPtr) {
    double currentTime = 0.0; // FIXME: get actual timestamp in seconds
    double multiplier = currentTime / controllerPtr->T;

    if (multiplier < 1) {
        PID_Controller primary = controllerPtr->primary;
        PID_Controller secondary = controllerPtr->secondary;

        primary.kP *= multiplier;
        primary.kI *= multiplier;
        primary.kD *= multiplier;

        secondary.kP *= multiplier;
        secondary.kI *= multiplier;
        secondary.kD *= multiplier;

        controllerPtr->primary = primary;
        controllerPtr->secondary = secondary;
    }
}

double calculateCascadedOutput(Cascaded_PID_Controller* controllerPtr, const double primarySetpoint, const double currentPrimaryState, const double currentSecondaryState) {
    PID_Controller primary = controllerPtr->primary;
    PID_Controller secondary = controllerPtr->secondary;

    double feedforward = 0.0; // FIXME: put actual feedforward calc here later
    double primaryOutput = calculate(&primary, currentPrimaryState, primarySetpoint);

    double cascadedOutput = calculate(&secondary, currentSecondaryState, primaryOutput + feedforward);

    controllerPtr->primary = primary;
    controllerPtr->secondary = secondary;

    return cascadedOutput;
}