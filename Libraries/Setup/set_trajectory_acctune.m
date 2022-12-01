% This script prepares sample trajectories for feedforward tuning
close all;
force_est = 5; %estimated force in Newtons
mass_sim = 1.23; % simulated mass in kg
s_rate = 2000; % sampling rate in Hz
s_period =  1/s_rate;

acc_est = force_est/mass_sim;

breaks = [0 0.11 0.37 0.67 0.93 1.04];
x = zeros(1,size(breaks,2)-1);
v = zeros(1,size(breaks,2)-1);
x(1) = 0;
v(1) = 0;
% a must have size(break,2)-1 elements
a = [acc_est -acc_est acc_est -acc_est acc_est]; 
if size(a,2) ~= size(breaks,2)-1
    fprintf('You must provide one acceleration value for each period! \n')
end

for i = 2:size(breaks,2)-1
    x(i) = 0.5*a(i-1)*(breaks(i)-breaks(i-1))^2 ...
        + v(i-1)*(breaks(i)-breaks(i-1)) ...
        + x(i-1);
    v(i) = a(i-1)*(breaks(i)-breaks(i-1)) ...
        + v(i-1);
end

coefs = [0.5*a v x];
pp = mkpp(breaks,coefs);

time_test = (0:s_period:breaks(end));
traj_test = ppval(pp,time_test);

figure(1)
hold on
plot(time_test,traj_test,'Color','blue')
scatter(breaks,ppval(pp,breaks))
% plot(time,vel,'Color','green')
% plot(time,acc,'Color','red')
 ylim([-0.05 0.05])
hold off