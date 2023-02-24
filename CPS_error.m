%% Error comparison code 
% Use this code to assess the error between each solution 

%analytical is "predicted"

%cps f zero vs analytical
RMSE_ana_cps_f_zero=rmse(analyt,cps_f_zero)


% %cps prescribed vs analytical
% RMSE_ana_cps_prescribe=rmse(ana_1,Heave_commanded_measured(:,2)/start_position_cm)');
% 
% %cps encoder vs analytical
% RSME_ana_cps_encoder=rmse(ana_1,(Heave_commanded_measured(:,3)/start_position_cm)');

%% 
plot(tim*((k/M)^0.5)/(2*pi),sol/start_position_cm);
hold on;
cps_f_zero=(Heave_of_ideal_CPS_cm(:,2)/start_position_cm)';
plot((i*omega_n)/(2*pi),cps_f_zero);
plot(Commanded_and_measured_position(:,1),Commanded_and_measured_position(:,2));
plot(Commanded_and_measured_position(:,1),Commanded_and_measured_position(:,3));
legend('analytical','unforced cps','CPS commanded','CPS measured');
ylabel('x/x_0');
xlabel('t*sqrt((k/M))/2pi')
%%
start_position_cm=5;
%%
maxes=[max(acc) max(veloc) max(posi)]