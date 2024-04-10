%%% modified to approximate mass changes

mdot1 = -1.5
mdot2 = -0.75
mdot3 = -.9

m0 = 100

t1 = 1.7 % throttle down
t2 = 30 % throttle back up

g = 10

Ft1 = 1500 % inital thrust
Ft2 = 700 % thrust after t1 and before t2
Ft3 = 900 % thrust after t2

syms x % matlab syntax stuff

Fx = piecewise(x < t1, Ft1, t1 < x < t2, Ft2, x>t2, Ft3) % thrust function

mdot = piecewise(x < t1, mdot1,t1 < x < t2, mdot2, x>t2, mdot3)

W = g * (int(mdot,0,x) + m0)

a = (Fx-W)/m

v = int(a,0,x)

s = int(v,0,x)

fplot(W,[0,40])