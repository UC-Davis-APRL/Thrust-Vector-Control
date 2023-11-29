Ix = 4.59;
Iy = 4.59;
Iz = 5.3;


A = [0 0 0 0 0 0;
    0 0 0 0 0 0;
    0 0 0 0 0 0;
    0.5 0 0 0 0 0;
    0 0.5 0 0 0 0;
    0 0 0.5 0 0 0];

B = [inv(Ix) 0 0; 
     0 inv(Iy) 0;
     0 0 inv(Iz);
     zeros(3)];


C = eye(6);

D = zeros(6,3);

Q = diag([2.5 2.5 2.5 300 300 300]);

R = diag([9 9 9]);


[K,S,P] = lqr(A,B,Q,R)

eig(A); % test
