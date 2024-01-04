% moments of inertia
Ix = 4.59;
Iy = 4.59;
Iz = 5.3;
J = diag([Ix Iy Iz]);


% goal conditions
G = transpose([0 0 0 0 0 0]);

% State space model matricies
A = [0 0 0 0 0 0;
    0 0 0 0 0 0;
    0 0 0 0 0 0;
    0.5 0 0 0 0 0;
    0 0.5 0 0 0 0;
    0 0 0.5 0 0 0];

B = [inv(J);
     zeros(3)];

C = eye(6);

D = zeros(6,3);

Q = diag([2.5 2.5 2.5 100 100 100]);

R = diag([9 9 9]);

open_system("modelsim")

    
% initial euler angle conditions
eul = deg2rad([10 5 -5]);

% conversion to quaternions
quat = eul2quat(eul);

% initial angular rate
omega = [0 0 0];
% full initial conditions
I = transpose([omega, quat(2:4)]);

% LQR calculion
[K,S,P] = lqr(A,B,Q,R);

    
set_param("modelsim","SimulationCommand","Start")



inv(J)
