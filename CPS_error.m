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