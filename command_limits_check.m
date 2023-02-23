%Checking for limits
start_position_cm=10;
M=10;
dampratio = 0.0015; % damping ratio %0 to 0.1
f_nat = 0.5; % natural frequency in Hz dF/U 1 here is 100hz in christins stuff
    k = (2*pi*f_nat)^2*M;
    c = 2*dampratio*sqrt(k*M);
%% max
max_a=max(acc);
max_v=max(veloc);
max_p=max(posi);
maxes=[max_a max_v max_p]
% error
RMSE_ana_cps_f_zero=rmse(analyt,cps_f_zero)