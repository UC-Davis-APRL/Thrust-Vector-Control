function [force_thrust_b, tau] = propForces(T,delx,dely, moment_arm)


force_thrust_b = T*[sin(dely)*cos(delx); -sin(delx); cos(dely)*cos(delx)]

tau = moment_arm * force_thrust;

end