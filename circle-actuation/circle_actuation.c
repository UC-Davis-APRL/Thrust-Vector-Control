#include <stdio.h>
#include <math.h>

#include "pid.h"

#define M_PI 3.1415

int main() {
    const double theta_z = 10.0 * (M_PI / 180.0); 
    const double startTheta = 0.0;
    const double endTheta = 2 * M_PI;
    const double thetaIncrement = (endTheta - startTheta) / 100.0;
    const double gimbleRadius = 5.0; // inches

    PID_Controller xActuatorController;
    // FIXME: tune PID coefficients
    xActuatorController.kP = 0.0;
    xActuatorController.kI = 0.0;
    xActuatorController.kD = 0.0;

    PID_Controller yActuatorController;
    // FIXME: tune PID coefficients
    yActuatorController.kP = 0.0;
    yActuatorController.kI = 0.0;
    yActuatorController.kD = 0.0;

    for (int i = 0; i <= 100; i++) {
        // FIXME: replace with code to get angles from rotary encoders
        double currentXTheta = 0.0;
        double currentYTheta = 0.0;

        double setpointTheta = thetaIncrement * i;
        double xSetpoint = asin(sin(theta_z) * cos(setpointTheta));
        double ySetpoint = asin(sin(theta_z) * sin(setpointTheta));
        printf("Theta(XY): %.2lf X Setpoint: %.2lf Y Setpoint: %.2lf\n", setpointTheta, xSetpoint, ySetpoint);

        double xActuatorVin = calculate(&xActuatorController, currentXTheta, xSetpoint);
        double yActuatorVin = calculate(&yActuatorController, currentYTheta, ySetpoint);

        /*
        Code to set input voltage for linear actuators here
        */
    }

    return 0;
}