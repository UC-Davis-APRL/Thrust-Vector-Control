disp ("hello");
function w2b_vec = world2body(world_vec, euler)

phi = euler(1);
theta = euler(2);
psi = euler(3);

A = [1 0 0 ; 0, cos(phi), -sin(phi); 0 0 1];

B = [cos(theta), 0, sin(theta); 0 1 0; -sin(theta), 0, cos(theta)];

C = [cos(psi), -sin(psi), 0; sin(psi), cos(psi), 0; 0 0 1];

w2b_vec = C * B * A * world_vec

end



function b2w_vec = body2world(body_vec, euler)

phi = euler(1);
theta = euler(2);
psi = euler(3);

A = [1 0 0 ; 0, cos(phi), -sin(phi); 0 0 1];

B = [cos(theta), 0, sin(theta); 0 1 0; -sin(theta), 0, cos(theta)];

C = [cos(psi), -sin(psi), 0; sin(psi), cos(psi), 0; 0 0 1];

b2w_vec = inv(A) * inv(B) * inv(C) * body_vec;

end


function accel_w = linear_kin_w(mass, euler, T, delx, dely)

accel_w = (1/mass) * (force_grav_w (mass) + body2world(propForce(T, delx, dely)(1), euler));

end

function accel_w = rot_kin_w(mass, euler, T, delx, dely)

accel_w = (1/mass) * (force_grav_w (mass) + body2world(propForce(T, delx, dely)(1), euler));

end




