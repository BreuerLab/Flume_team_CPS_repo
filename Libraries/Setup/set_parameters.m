% set parameters for varying u_star or k

D = 0.0508; % meters
M = 8.84; % kg 
zeta = 0.00134; % 0.00134 from Khalak '97 fig 2

u_est = 0.3; % 30 cm/s

% Pick one variable to vary, all others should be 0
vary_u_star = 1;
vary_k = 0;

if vary_u_star == 1
    u_star_min = 4;
    u_star_max = 8;
    u_star_step = 0.125;
    u_star = [(u_star_min:u_star_step:u_star_max),(u_star_max:-u_star_step:u_star_min)];
    u_star = repelem(u_star,2);

    steps = (u_star_max-u_star_min)/u_star_step + 1;

    c_test = 4*pi*M*zeta*u_est./(D*u_star);
    k_test = M*(2*pi*u_est./(D*u_star)).^2;

elseif vary_k == 1
    k_min = 200; % units of N/m
    k_max = 700;
    k_step = 25;
    
    steps = (k_max-k_min)/k_step + 1;

    k_test = [(k_max:-k_step:k_min),(k_min:k_step:k_max)];
    k_test = repelem(k_test,2);
    c_test = 0.11*ones(1,length(k_test));
    u_star = u_est/D*(sqrt(k_test/M)/(2*pi));

end

time_step =  60;
time_test = sort([time_step*(0:1:2*steps),time_step*(1:1:2*steps-1)+1]);
sim_time = max(time_test);



figure(1)
plot(time_test,c_test)
xlabel('time (s)')
ylabel('c values (kg/s)')
figure(2)
plot(time_test,k_test)
xlabel('time (s)')
ylabel('k values (N/m)')
figure(3)
plot(time_test,u_star)
xlabel('time (s)')
ylabel('U* values')