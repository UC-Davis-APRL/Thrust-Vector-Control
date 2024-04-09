t1 = 1.25
t2 = 18

g = 10

m = 100

W = m*g

Ft1 = 1800
Ft2 = 900
Ft3 = 1100

syms x

Fx = piecewise(x < t1,Ft1,t1 < x < t2,Ft2,x>t2,Ft3)

a = (Fx-W)/m

v = int(a,0,x)

s = int(v,0,x)

%fplot(a)


fplot(s,[0,40])


