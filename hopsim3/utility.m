disp ("hello");

function w2b_vec = world2body(world_vec, rotation)

rinv = [rotation(1), -rotation(2:4)]
w2b_vec = rotation *  world_vec  * rinv;

end




function error_quat = attitudeError(command_quat, quat)


    % qc1 = command_quat(1)
    % qc2 = command_quat(2)
    % qc3 = command_quat(3)
    % qc4 = command_quat(4)
    % 
    % 
    % A = [q4c, q3c, -q2c, -qc1;
    %     -q3c, q4c, q1c, -q2c;
    %     q2c, -q1c, q4c, -q3c;
    %     q1c, q2c, q3c, q4c]
    % 
    % error_quat = A * quat


    ''



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




