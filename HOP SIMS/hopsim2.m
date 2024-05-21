%% NO ROLL CONTROL

g = 9.81
mass = 0.627


l = 0.2251


I_x = 3.88 * 10^-2;
I_y = 3.87 * 10^-2;
I_z = 1.15 * 10^-3;

imat = diag([1/I_x,1/I_y,1/I_z])

A = [
    0 0 1 0 0 0 0 0 0 0;
    0 0 0 1 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 1 0 0;
    0 0 0 0 0 0 0 0 1 0;
    0 0 0 0 0 0 0 0 0 1;
    0 g 0 0 0 0 0 0 0 0;
    -g 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0]
   





B = [zeros(3,4);
    zeros(3,1), imat;
    zeros(5,4);
    1/mass, zeros(1,3)];


B(3,:)=[];
B(5,:)=[];
B(:,4)=[]


Q = diag([1 1     1 1     1 1 1    1 1 1])
R = 1;

V = 10;


[K,S,P] = lqr(A,B,Q,R)
K = round(K,5)

G = [0 0   0 0   0 0 1    0 0 0]'



open_system("hopsim2model")
set_param("hopsim2model", "SimulationCommand", "Start")

