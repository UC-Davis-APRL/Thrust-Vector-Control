%%% modified to approximate mass changes

mdot1 = -0.7
mdot2 = -0.4
mdot3 = -0.7

m0 = 100

t1 = 4 % throttle down
t2 = 15 % throttle back up

g = 10

Ft1 = 1300 % inital thrust
Ft2 = 800 % thrust after t1 and before t2
Ft3 = 1300 % thrust after t2

syms x % matlab syntax stuff

Fx = piecewise(x < t1, Ft1, t1 < x < t2, Ft2, x>t2, Ft3) % thrust function

mdot = piecewise(x < t1, mdot1,t1 < x < t2, mdot2, x>t2, mdot3)

W = g * (int(mdot,0,x) + m0)

a = (Fx-W)/m0

v = int(a,0,x)

s = int(v,0,x)

fplot(s,[0,50])
xlabel('t(s)') 
ylabel('Vertical Displacement (m)')