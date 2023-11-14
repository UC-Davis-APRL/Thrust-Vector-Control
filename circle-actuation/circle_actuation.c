#include <stdio.h>
#include <math.h>

#define M_PI 3.1415

int main() {
    const double theta_z = 10.0 * (M_PI / 180.0); 
    const double startTheta = 0.0;
    const double endTheta = 2 * M_PI;
    const double thetaIncrement = (endTheta - startTheta) / 100.0;
    const double gimbleRadius = 5.0; // inches

    for (int i = 0; i <= 100; i++) {
        double currentTheta_xy = thetaIncrement * i;
        double xAct = gimbleRadius * sin(theta_z) * cos(currentTheta_xy);
        double yAct = gimbleRadius * sin(theta_z) * sin(currentTheta_xy);
        printf("Theta(XY): %.2lf X Actuation: %.2lf Y Actuation: %.2lf\n", currentTheta_xy, xAct, yAct);
    }

    return 0;
}