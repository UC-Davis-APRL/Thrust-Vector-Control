% moments of inertia
Ix = 4.59;
Iy = 4.59;
Iz = 5.3;
J = [Ix 0 0; 0 Iy 0; 0 0 Iz]



% initial euler angle conditions
eul = [0 pi/36 0]

% conversion to quaternions
quat = eul2quat(eul)

% initial angular rate
omega = [0 0 0]
% full initial conditions
I = transpose([omega, quat(1:3)]);

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

% LQR calculion
[K,S,P] = lqr(A,B,Q,R);

open_system("modelsim")
	
set_param("modelsim","SimulationCommand","Start")