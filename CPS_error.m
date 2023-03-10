%% Error comparison code 
%%
x_0=5;
% Use this code to assess the error between each solution 

%analytical is "predicted"
%cps f zero vs analytical
cps_f_zero=(Heave_of_ideal_CPS_cm(:,2)/x_0)';

RMSE_ana_cps_f_zero=round(rmse(analyt,cps_f_zero)*10000)/100;

%cps prescribed vs analytical
RMSE_ana_cps_commanded=round((rmse(analyt,(Commanded_and_measured_position(:,2)/x_0)'))*10000)/100;

%cps encoder vs analytical
RMSE_ana_cps_encoder=round((rmse(analyt,(Commanded_and_measured_position(:,3)/x_0)'))*10000)/100;

%cps commanded vs cps encoder
RMSE_cps_commanded_cps_encoder=round((rmse((Commanded_and_measured_position(:,3)/x_0)',(Commanded_and_measured_position(:,2)/x_0)'))*10000)/100;

%analytical vs cps encoder
RMSE_ana_cps_encoder=round((rmse(analyt,(Commanded_and_measured_position(:,3)/x_0)'))*10000)/100;