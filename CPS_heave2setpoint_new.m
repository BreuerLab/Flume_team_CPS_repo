% Use this to move the heave motor to setpoint position (in meters) gently 
% in between CPS trials (using CPS_*.slx to zero the motor position is 
% quite violent)
% WARNING: Use this script only after running the CPS and all dependent
% scripts or unstable motor motion may occur 
% (that is, make sure to run daq_setup_3rigs_CPS_PIV.m, CPS_setup.m, CPS_tare.mdl, and CPS_*.slx) 

input_heave_meters = 0.05; % Initial heave position in meters
output_heave_volts = input_heave_meters*(1/0.03)+0.015; % 0.03 meters/Volt and 0.015 Volt bias

s.outputSingleScan([0 0 output_heave_volts]);