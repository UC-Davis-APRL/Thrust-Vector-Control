#pragma once

#include <Stepper.h>

#include "PID_Controller.h"

class Ereg_Controller {
    private:
        double ullageVolumeThreshold;
        uint16_t currentPosition;

        PID_Controller& setpointController;
        Stepper& valveStepper;
    
    public:
        Ereg_Controller(PID_Controller& pidController, Stepper& valveStepper, const double ullageVolumeThreshold);

        void updateGains(const double currentUllageVolume);
        void setEnginePressure(const double a,
                               const double b,
                               const double c,
                               const double pressureSetpoint,
                               const double currentPressure);
};