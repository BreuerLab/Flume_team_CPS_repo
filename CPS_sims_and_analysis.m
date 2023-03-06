%run setup_CPS_parameters and tare before first run 
%% System parameters
M = 7; % 10 simulated mass in kg
dampratio = 0.05; % 0.1 damping ratio
f_nat = 0.5; % 1 natural frequency in Hz
    k = (2*pi*f_nat)^2*M;
    c = 2*dampratio*sqrt(k*M);
duration_sim = 2*(M/c)*8; % Total duration of simulink experiment, in seconds
trial_name="ringdown-cyl-M"+M+"-d"+dampratio+"-F"+f_nat;
trial_name=strrep(trial_name,".","_");
%% tare
set_param('CPS_tare_Eva','SimulationCommand','start');
disp('tared');
%% Set heave
set_param('set_heave_Eva','SimulationCommand','start');
disp('initial heave set');
%% run CPS
set_param('CPS_Eva','SimulationCommand','start');
disp('cps run complete');
%% analytical solution
analytical_solution_cps;
disp('analytical solution complete');
%% CPS unforced virtual experiment 
sim('Ideal_CPS_F_as_zero.slx');
disp('virtual unforced simulation complete');
%% Error assessment
CPS_error
disp('error analysis complete')
%saveas(fig_error,trial_name+"-error-plot.png");
%saveas(fig_forces,trial_name+"-forces-plot.png");
%% Outputting stats