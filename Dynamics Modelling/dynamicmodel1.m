
t1 = 1.25 % throttle down
t2 = 18 % throttle back up

g = 10

m = 100

W = m*g


Ft1 = 1800 % inital thrust
Ft2 = 900 % thrust after t1 and before t2
Ft3 = 1100 % thrust after t2

syms x % matlab syntax stuff

Fx = piecewise(x < t1,Ft1,t1 < x < t2,Ft2,x>t2,Ft3) % thrust function

a = (Fx-W)/m

v = int(a,0,x)

s = int(v,0,x)

fplot(s,[0,24]) 