#pragma once

class PID_Controller {
  private:
    double kP;
    double kI;
    double kD;

    uint32_t derivativeTimeStart;
    uint32_t integralUpdateTimeStart;

    double derivativePrevError;
    
    double integralStartError;
    double integralPrevError;
    double integral;
  public:
    PID_Controller() = default;
    PID_Controller(double kP, double kI, double kD);

    double getP();
    double getI();
    double getD();
    
    void setP(double P);
    void setI(double I);
    void setD(double D);

    double calculate(const double currentState, const double setpoint);
};