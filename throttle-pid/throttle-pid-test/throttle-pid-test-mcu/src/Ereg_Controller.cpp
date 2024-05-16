#include <cmath>
#include <Arduino.h>
#include <Servo.h>

#include "Ereg_Controller.h"
#include "PID_Controller.h"

Ereg_Controller::Ereg_Controller(PID_Controller& pidController,
                                 Servo& valveServo, 
                                 double ullageVolumeThreshold): setpointController(pidController), valveServo(valveServo) {
    this->ullageVolumeThreshold = ullageVolumeThreshold;

    servoOffset = 94;
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
    double valveFeedforward = (7.84033 + ((-0.7624865 - 7.84033) / (1 + pow(desiredCv / 7243.604, 0.1969319)))) * 90;
    double valveSetpoint = setpointController.calculate(currentPressure, pressureSetpoint) + valveFeedforward;

    uint16_t servoPulseWidth = (uint16_t)(map(valveSetpoint, 0, 90, 1000, 1500)) + servoOffset;
    valveServo.writeMicroseconds(servoPulseWidth);
}