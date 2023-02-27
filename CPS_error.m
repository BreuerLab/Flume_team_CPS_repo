%% Error comparison code 
%%
x_0=5;
% Use this code to assess the error between each solution 

%analytical is "predicted"
hold off;
set(gcf, 'Position',  [100, 100, 710, 500])
%cps f zero vs analytical
cps_f_zero=(Heave_of_ideal_CPS_cm(:,2)/x_0)';

RMSE_ana_cps_f_zero=rmse(analyt,cps_f_zero);

%cps prescribed vs analytical
RMSE_ana_cps_commanded=rmse(analyt,(Commanded_and_measured_position(:,2)/x_0)');

%cps encoder vs analytical
RMSE_ana_cps_encoder=rmse(analyt,(Commanded_and_measured_position(:,3)/x_0)');

%cps commanded vs cps encoder
RMSE_cps_commanded_cps_encoder=rmse((Commanded_and_measured_position(:,3)/x_0)',(Commanded_and_measured_position(:,2)/x_0)');
%% 
plot(tim*((k/M)^0.5)/(2*pi),sol/x_0);
hold on;
plot((i*omega_n)/(2*pi),cps_f_zero);
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi),Commanded_and_measured_position(:,2)/x_0);
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi),Commanded_and_measured_position(:,3)/x_0);
legend('analytical','unforced cps','CPS commanded','CPS measured');
ylabel('heave position(x/x_0)');
xlabel('time(cycles)')
xlim([0 10]);
title("Mass: "+M+ " Damping ratio: "+dampratio+" Frequency: "+f_nat);
dim = [0.5 0.0 0.3 0.3];
str = {"RMS Error:","unforced CPS vs analytical="+ (round(RMSE_ana_cps_f_zero*10000)/100)+"%","CPS commanded vs analytical="+(round(RMSE_ana_cps_commanded*10000)/100)+"%","CPS encoder vs CPS commanded="+(round(RMSE_cps_commanded_cps_encoder*10000)/100)+"%"};
annotation('textbox',dim,'String',str,'FitBoxToText','on');
%annotation('textbox', [0.5, 0.2, 0.1, 0.1], 'String', "hi")
%%
%maxes=[max(acc) max(veloc) max(posi)]
