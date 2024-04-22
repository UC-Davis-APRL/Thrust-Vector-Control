#ifndef PID_H
#define PID_H

class PID_Controller {
  private:
    double kP;
    double kI;
    double kD;

    uint32_t timeStart;
    
    double startError;
    double prevError;
    double integral;
  public:
    PID_Controller(double kP, double kI, double kD);

    double calculate(const double currentState, const double setpoint);
};

#endif