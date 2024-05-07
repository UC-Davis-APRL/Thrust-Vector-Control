g = 9.81
mass = 0.627

I_x = 3.88 * 10^-2;
I_y = 3.87 * 10^-2;
I_z = 1.15 * 10^-3;

imat = diag([1/I_x,1/I_y,1/I_z])

A = [zeros(3), eye(3), zeros(3,6);
    zeros(3,12);
    zeros(3,9), eye(3);
    0, g, zeros(1,10);
    -g, zeros(1,11);
    zeros(1,12)
    ]
   


B = [zeros(3,4);
    zeros(3,1), imat;
    zeros(5,4);
    1/mass, zeros(1,3)]

Q = diag([1 1 1    1 1 1    100 100 100     1 1 1])
R = 1

[K,S,P] = lqr(A,B,Q,R)

G = [0 0 0     0 0 0    1 0 0     0 0 0]'



open_system("hopsim1model")
set_param("hopsim1model", "SimulationCommand", "Start")

