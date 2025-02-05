#include <cmath>
#include <Arduino.h>
#include <Stepper.h>

#include "Ereg_Controller.h"
#include "PID_Controller.h"

Ereg_Controller::Ereg_Controller(PID_Controller& pidController,
                                 Stepper& valveServo, 
                                 double ullageVolumeThreshold): setpointController(pidController), valveStepper(valveStepper) {
    this->ullageVolumeThreshold = ullageVolumeThreshold;

    currentPosition = 0;
}

void Ereg_Controller::updateGains(const double currentUllageVolume) {
    double multiplier = currentUllageVolume / ullageVolumeThreshold;

    if (multiplier < 1) {
        setpointController.setP(setpointController.getP() * multiplier);
        setpointController.setI(setpointController.getI() * multiplier);
        setpointController.setD(setpointController.getD() * multiplier);
    }
}

void Ereg_Controller::setEnginePressure(
                               const double a,
                               const double fluidDensity,
                               const double tankPressure,
                               const double pressureSetpoint,
                               const double currentPressure
                               ) {
    double b = -2 * fluidDensity;
    double c = 2 * fluidDensity * tankPressure;
    
    double desiredCv = (a * pressureSetpoint) / (sqrt((b * pressureSetpoint) + c));

    // Lander
    // double valveFeedforward = (2349.578 + ((-0.4532749 - 2349.578) / (1 + pow(desiredCv / 139686000, 0.2498469)))) * 30;
    // valveFeedforward = constrain(valveFeedforward, 0, 30);

    // DPF
    double valveFeedforward = -8.21992 + (56.45416 * desiredCv) - (105.6788 * pow(desiredCv, 2)) + (69.18414 * pow(desiredCv, 3));
    valveFeedforward = constrain(valveFeedforward, 0, 5);
    valveFeedforward *= 200;

    double valveSetpoint = setpointController.calculate(currentPressure, pressureSetpoint) + valveFeedforward;

    // Lander
    // int valveStepGoal = map(valveSetpoint, 0, 30, 0, 200);

    // DPF
    int valveStepGoal = valveSetpoint;

    valveStepper.step(valveStepGoal - currentPosition);
    currentPosition = valveStepGoal;
}