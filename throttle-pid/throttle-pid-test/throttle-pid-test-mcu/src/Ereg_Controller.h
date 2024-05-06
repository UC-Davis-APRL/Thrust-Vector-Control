#pragma once

#include <Servo.h>

#include "PID_Controller.h"

class Ereg_Controller {
    private:
        double ullageVolumeThreshold;
        uint16_t servoOffset;

        PID_Controller setpointController;
        Servo valveServo;
    
    public:
        Ereg_Controller(PID_Controller pidController, Servo valveServo, double ullageVolumeThreshold);

        void updateGains(const double currentUllageVolume);
        void setEnginePressure(const double a,
                               const double b,
                               const double c,
                               const double pressureSetpoint,
                               const double currentPressure);
};