#include <CytronMotorDriver.h>
#include <cmath>

#include "PID_Controller.h"

const double theta_z = 10.0 * (M_PI / 180.0); 
const double startTheta = 0.0;
const double endTheta = 2 * M_PI;
const double thetaIncrement = (endTheta - startTheta) / 100.0;
const double gimbleRadius = 5.0; // inches

// FIXME: replace with actual pin numbers
const int xPWM = 1;
const int xDIR = 2;

// FIXME: replace with actual pin numbers
const int yPWM = 3;
const int yDIR = 4; 

CytronMD xActuator(PWM_DIR, xPWM, xDIR);
CytronMD yActuator(PWM_DIR, yPWM, yDIR);

// FIXME: tune PID coefficients
PID_Controller xController(0.0, 0.0, 0.0); 
PID_Controller yController(0.0, 0.0, 0.0);

void setup() {
  for (int i = 0; i <= 100; i++) {
      // FIXME: replace with code to get angles from rotary encoders
      double currentXTheta = 0.0;
      double currentYTheta = 0.0;

      double setpointTheta = thetaIncrement * i;
      double xSetpoint = asin(sin(theta_z) * cos(setpointTheta));
      double ySetpoint = asin(sin(theta_z) * sin(setpointTheta));

      double xActuatorVin = xController.calculate(currentXTheta, xSetpoint);
      double yActuatorVin = yController.calculate(currentYTheta, ySetpoint);

      int xActuatorDutyCycle = (xActuatorVin / 12.0) * 255;
      int yActuatorDutyCycle = (yActuatorVin / 12.0) * 255;

      xActuator.setSpeed(xActuatorDutyCycle);
      yActuator.setSpeed(yActuatorDutyCycle);
  }

  xActuator.setSpeed(0);
  yActuator.setSpeed(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
