import mlreportgen.report.*
import mlreportgen.dom.*

Doc=Document(file_name+"-report",'docx','report_template.dotx');
open(Doc)

%parameters
moveToNextHole(Doc)
append(Doc,M) %mass
moveToNextHole(Doc)
append(Doc,model_shape) %model type
moveToNextHole(Doc)
append(Doc,dampratio) %ramping ratio
moveToNextHole(Doc)
append(Doc,setpoint)%initial heave
moveToNextHole(Doc)
append(Doc,f_nat) %frequency
moveToNextHole(Doc)
append(Doc,enviornment)%enviornment
moveToNextHole(Doc)
append(Doc,c) %c
moveToNextHole(Doc)
append(Doc,T) %time step
moveToNextHole(Doc)
append(Doc,k)%k

%root mean square error
moveToNextHole(Doc)
append(Doc,RMSE_ana_cps_f_zero)
moveToNextHole(Doc)
append(Doc,RMSE_ana_cps_commanded)
moveToNextHole(Doc)
append(Doc,RMSE_cps_commanded_cps_encoder)
moveToNextHole(Doc)
append(Doc,RMSE_ana_cps_encoder)

%plots
moveToNextHole(Doc)

