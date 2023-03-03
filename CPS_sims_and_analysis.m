%run setup_CPS_parameters and tare before first run 


%% System parameters
M = 10; % 10 simulated mass in kg
dampratio = 0.1; % 0.1 damping ratio
f_nat = 1; % 1 natural frequency in Hz
    k = (2*pi*f_nat)^2*M;
    c = 2*dampratio*sqrt(k*M);
duration_sim = 2*(M/c)*8; % Total duration of simulink experiment, in seconds
trial_name="ringdown-cyl-M"+M+"-d"+dampratio+"-F"+f_nat;
trial_name=strrep(trial_name,".","_");
%% Set heave
%sim('set_heave_Eva.slx');
%% run CPS
%sim('CPS_Eva.slx');
%% analytical solution
analytical_solution_cps;
%% CPS unforced virtual experiment 
sim('Ideal_CPS_F_as_zero.slx');
%% Error assessment
hold off;
CPS_error
saveas(fig_error,trial_name+"-error-plot.png");
saveas(fig_forces,trial_name+"-forces-plot.png");
%% Outputting stats