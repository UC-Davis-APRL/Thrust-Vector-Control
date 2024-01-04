Ix = 79.06;
Iy = 79.06;
Iz = 0.77;
m = 68.04

g = 9.81;

J = diag([Ix Iy Iz]);

A = [0 0 0 1 0 0 0 0 0 0 0 0;
    0 0 0 0 1 0 0 0 0 0 0 0;
    0 0 0 0 0 1 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 1 0 0;
    0 0 0 0 0 0 0 0 0 0 1 0;
    0 0 0 0 0 0 0 0 0 0 0 1;
    0 g 0 0 0 0 0 0 0 0 0 0;
    -g 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0];

B = [zeros(3,4);
    [zeros(3,1) inv(J)];
    zeros(5,4);
    inv(m) 0 0 0];

C = eye(12);

D = zeros(12,4);

Q = diag([100 100 100 1 1 1 10 10 10 5 5 5]);

R = 1

initialConditions = [0 0 0 0 0 0 0 0 0 0 0 0]
goalConditions = [0 0 0 0 0 0 0 0 0 0 0 0]


[K,S,P] = lqr(A,B,Q,R);

set_param("fullmodel","SimulationCommand","Start")