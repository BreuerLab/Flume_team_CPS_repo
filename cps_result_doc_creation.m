% RMSE_ana_cps_f_zero=round(rmse(analyt,cps_f_zero)*10000)/100;
% %%

import mlreportgen.report.*
import mlreportgen.dom.*
Doc=Document(trial_name+"-report",'docx','report_template_eva.dotx');
open(Doc)

%parameters
moveToNextHole(Doc)
append(Doc,M) %mass
moveToNextHole(Doc)
append(Doc,model_shape) %model type
moveToNextHole(Doc)
append(Doc,num2str(round(dampratio,2))) %damping ratio
moveToNextHole(Doc)
append(Doc,setpoint)%initial heave
moveToNextHole(Doc)
append(Doc,f_nat) %frequency
moveToNextHole(Doc)
append(Doc,enviornment)%enviornment
moveToNextHole(Doc)
append(Doc,num2str(round(c,2))) %c
moveToNextHole(Doc)
append(Doc,T) %time step
moveToNextHole(Doc)
append(Doc,num2str(round(k,2)))%k

%root mean square error
moveToNextHole(Doc)
append(Doc,num2str(round(RMSE_ana_cps_f_zero,2)))
moveToNextHole(Doc)
append(Doc,num2str(round(RMSE_ana_cps_commanded,2)))
moveToNextHole(Doc)
append(Doc,num2str(round(RMSE_cps_commanded_cps_encoder,2)))
moveToNextHole(Doc)
append(Doc,num2str(round(RMSE_ana_cps_encoder,2)))

import mlreportgen.report.*
import mlreportgen.dom.*
%plots
moveToNextHole(Doc)
append(Doc,img2)

moveToNextHole(Doc)
append(Doc,img1)

moveToNextHole(Doc)
append(Doc,img3)

moveToNextHole(Doc)
append(Doc,img4)

moveToNextHole(Doc)
append(Doc,img5)

close(Doc)

