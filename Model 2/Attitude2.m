Ix = 79.06;
Iy = 79.06;
Iz = 0.77;
m = 100;

g = 9.81;


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