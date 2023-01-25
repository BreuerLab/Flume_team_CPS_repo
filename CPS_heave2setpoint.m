% Use this to move the heave motor to setpoint position (in meters) gently 
% in between CPS trials (using CPS_*.slx to zero the motor position is 
% quite violent)
% WARNING: Use this script only after running the CPS and all dependent
% scripts or unstable motor motion may occur 
% (that is, make sure to run daq_setup_3rigs_CPS_PIV.m, CPS_setup.m, CPS_tare.mdl, and CPS_*.slx) 

setpoint = 0.00; % Desired setpoint position in meters

inputScan = inputSingleScan(s); % Measure daq input channels
input_heave = inputScan(8); % Extract heave channel (currently channel 8) datapoint, measured in volts
input_heave_meters = input_heave*(-0.03/5.68); % Measured heave in meters


while abs(input_heave_meters-setpoint) > 5e-4 % Reduce heave to below threshold value in meters

    % coarse adjustment followed by fine adjustment
        if input_heave_meters-setpoint > 5e-4 % for heave above the threshold, reduce
            heave = input_heave_meters - 5e-4;
        elseif input_heave_meters-setpoint < -5e-4 % for heave below the threshold, increase
            heave = input_heave_meters + 5e-4;
%         elseif input_heave_meters-setpoint > 1e-4 % for heave above the threshold, reduce
%             heave = input_heave_meters - 1e-4;
%         elseif input_heave_meters-setpoint < -1e-4 % for heave below the threshold, increase
%             heave = input_heave_meters + 1e-4;
        end
        
        if abs(heave) > 0.06  % Trying to avoid error caused by analog input and motor control decoupling...
            % Try restarting motor and zero-ing analong input if this error
            % occurs
            error('Output heave is too large!')
        end
    output_heave = heave*(-1/0.03); % Convert from input in meters to output in volts
    
    % Move the heave motor, config. for 3 output channels with the 3rd
    % channel being analogoutput for heave motor
    s.outputSingleScan([0 0 output_heave]) 
    
    pause(0.05); % delay so the motor does not jerk
    inputScan = s.inputSingleScan;
    input_heave = inputScan(8); % measured in volts
    input_heave_meters = input_heave*(-0.03/5.68); % Measured heave in meters
%     disp(input_heave_meters)
end

disp(['Heave motor moved to ',num2str(input_heave_meters*100), ' cm']);
