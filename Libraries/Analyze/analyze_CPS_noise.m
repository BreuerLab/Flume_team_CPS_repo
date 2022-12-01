close all; 
trials = 9; % 9 trials so far
timesteps = 60001;

set(0,'defaultAxesFontSize',24); set(0,'defaultAxesFontName','Arial');
set(0,'defaultLineLineWidth',3);

Forces = zeros(trials,6,timesteps);
ForcesStdDevs = zeros(trials,6);
SensorVoltages = zeros(trials,6,timesteps);
SensorVoltagesStdDevs = zeros(trials,6);

for trial = 1:trials 
    % Data location on home computer
% load(['C:\Users\Joel\Dropbox\Brown\Data\2021_3Fall\20220119_NoiseTest_wCylinWater_',num2str(trial),'.mat'])
    % Data location on flume computer
load(['C:\Users\jnewbolt\Documents\MATLAB\CPS code\Data\2021_3Fall\20220119_NoiseTest_wCylinWater_',num2str(trial),'.mat'])

time = ForcesAndTorques.time;
Forces(trial,:,:) = ForcesAndTorques.signals.values(1,:,:); % 1x6x60001
ForcesStdDevs(trial,:,:) = ForcesAndTorquesStdDevs.signals.values(1,:,end); % 1x6x60001
SensorVoltages(trial,:,:) = ForceSensorVoltages.signals.values(:,:)'; % 60001x6
SensorVoltagesStdDevs(trial,:,:) = ForceSensorVoltageStdDevs.signals.values(end,:)'; % 60001x6

end

figure(1)
plot(time,squeeze(Forces(5,1,:)))
title('Noise test- sinusoidal y-motion, flume off')
xlabel('Time (s)')
ylabel('Forces and Torques (N and N*m)')
legend('F transverse', 'F streamwise', 'F vertical', 'M transverse', 'M streamwise', 'M vertical','Location','northwest')
movegui('northwest')


figure(2)
grouplabels = categorical({'Off','y-motor','\theta -motor','both motors','flume only','motors and flume','y-motion only',...
    '\theta -motion only','hand-driven y-motion'});
grouplabels = reordercats(grouplabels,{'Off','y-motor','\theta -motor','both motors','flume only','motors and flume','y-motion only',...
    '\theta -motion only','hand-driven y-motion'});
 bar(grouplabels, ForcesStdDevs)
 title('Noise tests')
xlabel('Conditions')
ylabel('Std. Devs. of Forces and Torques (N and N*m)')
legend('F transverse', 'F streamwise', 'F vertical', 'M transverse', 'M streamwise', 'M vertical','Location','northwest')
movegui('southwest')

figure(3)
plot(time,squeeze(SensorVoltages(6,:,:)))
title('Noise test- motors and flume on')
xlabel('Time (s)')
ylabel('Force Sensor Voltages (V)')
legend('F transverse', 'F streamwise', 'F vertical', 'M transverse', 'M streamwise', 'M vertical','Location','northwest')
movegui('northeast')

figure(4)
bar(grouplabels,SensorVoltagesStdDevs)
title('Noise tests')
xlabel('Conditions')
ylabel('Std. Devs. of Force Sensor Voltages (V)')
legend('F transverse', 'F streamwise', 'F vertical', 'M transverse', 'M streamwise', 'M vertical','Location','northwest')
movegui('southeast')