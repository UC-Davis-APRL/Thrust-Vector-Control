

l=1;
d=1;
R=l*sin(degtorad(10));

for t = 0:(pi/10):(pi/2)
    r1 = R*cos(t);
    r2 = R*sin(t);
    R = sqrt(r1^2+r2^2); %test (passed)
    s1 = (d*r1) / (2*l)
    s2 = (d*r2) / (2*l)

end
