% Use this to move motor to a set position 
% Eva Erickson 1/20/2023
% run after setup_3rig_CPS_PIV 
% cosine fuction to move from  last_out = [0 0 0 0 0 0 0] in voltages to heave setpoint
%t=10; %set this 
setpoint = 0.02; %desired heave in meters
setpoint_voltages= [ last_out(1:5) -setpoint/0.03 last_out(7)];%6th index is wallace heave, this is voltages now

if exist('end_voltage','var') == 1 %is null if cps has not been run yet
    last_out(6)=end_voltage;
end
%%
duration = 10; % Time it takes to complete the move in seconds
timee=0:T:duration/2;
amp=0.5*(setpoint_voltages(:,6)-last_out(:,6));
f=amp*(1-cos(2*pi*(1/duration)*timee))+last_out(:,6); %-amp*sin(...+pi/2)+last_out+amp
points_to_move_wallace=f';
plot(timee, points_to_move_wallace);
%points_to_move_wallace=linspace(last_out(:,6),setpoint_voltages(:,6),s.Rate*t)';
z=ones(size(points_to_move_wallace));
all_volt=[setpoint_voltages(1:5).*z points_to_move_wallace setpoint_voltages(7).*z];

%%
dat = readwrite(s,all_volt,"OutputFormat","Matrix");
last_out=all_volt(end,:); %voltages
%%
start_position_meters=last_out(6)*-0.03;