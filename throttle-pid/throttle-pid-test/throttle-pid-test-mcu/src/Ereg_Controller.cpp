#include <cmath>
#include <Arduino.h>
#include <Servo.h>

#include "Ereg_Controller.h"
#include "PID_Controller.h"

Ereg_Controller::Ereg_Controller(PID_Controller& pidController,
                                 Servo& valveServo, 
                                 double ullageVolumeThreshold): setpointController(pidController), valveServo(valveServo) {
    this->ullageVolumeThreshold = ullageVolumeThreshold;

    servoOffset = -288;
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
    double valveFeedforward = (2349.578 + ((-0.4532749 - 2349.578) / (1 + pow(desiredCv / 139686000, 0.2498469)))) * 30;
    valveFeedforward = constrain(valveFeedforward, 0, 30);
    double valveSetpoint = setpointController.calculate(currentPressure, pressureSetpoint) + valveFeedforward;

    uint16_t servoPulseWidth = (uint16_t)(map(valveSetpoint, 0, 90, 1000, 2000)) + servoOffset;
    valveServo.writeMicroseconds(servoPulseWidth);
}