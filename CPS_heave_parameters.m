% Run this prior to using the simulink code to move motor to a set position 
% Eva Erickson 2/1/2023

setpoint = 2; %desired heave in cm
duration = 10; % Time it takes to complete the move in seconds
amp=(setpoint-start_position_cm)/-6;
