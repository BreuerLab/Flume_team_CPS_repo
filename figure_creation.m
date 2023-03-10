%figure creation
trial_name="ringdown-"+model_shape+"-M"+M+"-d"+dampratio+"-F"+f_nat;
trial_name=strrep(trial_name,".","_");
maxylim=(Commanded_and_measured_position(end,1)*omega_n)/(2*pi);

%% Error aka just the normal heave plots

fig_error=figure('Name','RMSE_error_plot');
%set(gcf,'position',[10,10,800,600])

plot(tim*((k/M)^0.5)/(2*pi),sol/x_0, 'Color', [0 0.4470 0.7410]); %analytical
hold on;
plot((i*omega_n)/(2*pi),cps_f_zero, 'Color',[0.4940 0.1840 0.5560]); %unforced cps
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi),Commanded_and_measured_position(:,2)/x_0, 'Color',[0.8500 0.3250 0.0980]); %cps commanded
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi),Commanded_and_measured_position(:,3)/x_0,'Color',[0.9290 0.6940 0.1250]); %cps encoder
legend('analytical','unforced virtual cps','CPS commanded','CPS measured','Fontsize',13);
ylabel('heave position(x/x_0)','FontSize',16);
xlabel('time(cycles)','FontSize',16)
xlim([0 maxylim]);
title("Mass: "+M+ " Damping ratio: "+dampratio+" Frequency: "+f_nat,'FontSize',16);
% dim = [0.5 0.0 0.3 0.3];
% str = {"RMS Error:","unforced CPS vs analytical="+ RMSE_ana_cps_f_zero+"%","CPS commanded vs analytical="+RMSE_ana_cps_commanded+"%","CPS encoder vs CPS commanded="+RMSE_cps_commanded_cps_encoder+"%","analytical vs CPS encoder="+RMSE_ana_cps_encoder+"%"};
% annotation('textbox',dim,'String',str,'FitBoxToText','on');

%% Forces
fig_forces=figure('Name','forces_plot');

plot((forces(:,1)*omega_n)/(2*pi),forces(:,2));
hold on;
plot((forces(:,1)*omega_n)/(2*pi),forces(:,3));
plot((forces(:,1)*omega_n)/(2*pi),forces(:,4),'LineWidth',4,'Color',[0.3010 0.7450 0.9330]);
legend('Fy','actual mass * measured acceleration','filtered FY + ma','FontSize',11);
xlabel('time (cycles)','FontSize',16)
ylabel('force (N)','FontSize',16);
xlim([0 maxylim]);
title("forces over time",'FontSize',16);
%% Displacement difference
fig_diff=figure('Name','difference_plot');

encoder_vs_commanded_position=(Commanded_and_measured_position(:,3)'-Commanded_and_measured_position(:,2)')/x_0;
analytical_vs_commanded=analyt-(Commanded_and_measured_position(:,2)/x_0)';
analytical_vs_encoder=analyt-(Commanded_and_measured_position(:,3)/x_0)';
analytical_vs_unforced=analyt-cps_f_zero;
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi), analytical_vs_unforced,'Color', [0 0.4470 0.7410]) % analytical_vs_unforced
hold on;
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi), analytical_vs_commanded,'Color',[0.4940 0.1840 0.5560]) % analytical_vs_commanded
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi), analytical_vs_encoder,'Color',[0.8500 0.3250 0.0980]) %analytical_vs_encoder
plot((Commanded_and_measured_position(:,1)*omega_n)/(2*pi), encoder_vs_commanded_position,'Color',[0.9290 0.6940 0.1250]) % encoder_vs_commanded_position
legend('analytical vs unforced virtual cps','analytical vs CPS commanded','analytical vs CPS measured','CPS measured vs CPS commanded','Fontsize',11);
ylabel('difference in heave position(x/x_0)','FontSize',16);
xlabel('time(cycles)','FontSize',16)
xlim([0 maxylim]);
title('heave difference over time','FontSize',16);
%% Lag plot
lag_ana_vs_unforcedcps=lag_code(analyt',cps_f_zero');
lag_ana_vs_cps_com=lag_code(analyt',Commanded_and_measured_position(:,2)/x_0);
lag_com_vs_enc=lag_code(Commanded_and_measured_position(:,2)/x_0,Commanded_and_measured_position(:,3)/x_0);
lag_ana_vs_cps_enc=lag_code(analyt',Commanded_and_measured_position(:,3)/x_0);
maxlag=max([lag_ana_vs_unforcedcps(1) lag_ana_vs_cps_com(1) lag_com_vs_enc(1) lag_ana_vs_cps_enc(1)]);


fig_lag= figure('Name','lag_plot');
left_color = [0 0 0];
right_color = [0 0 0];
set(fig_lag,'defaultAxesColorOrder',[left_color; right_color]);

yyaxis right
plot(0.75:0.5:((size(lag_ana_vs_unforcedcps)/2)-0.25),lag_ana_vs_unforcedcps(1:end-1),'-*','Color', [0 0.4470 0.7410])
hold on;
plot(0.75:0.5:((size(lag_ana_vs_cps_com)/2)-0.25),lag_ana_vs_cps_com(1:end-1),'-*','Color',[0.4940 0.1840 0.5560])
plot(0.75:0.5:((size(lag_ana_vs_cps_enc)/2)-0.25),lag_ana_vs_cps_enc(1:end-1),'-*','Color',[0.8500 0.3250 0.0980])
plot(0.75:0.5:((size(lag_com_vs_enc)/2)-0.25),lag_com_vs_enc(1:end-1),'-*','Color',[0.9290 0.6940 0.1250])

xlabel('cycles','FontSize',16)
ylabel('ms','Color','k','FontSize',16)
legend('analytical vs unforced virtual cps','analytical vs CPS commanded','analytical vs CPS measured','CPS measured vs CPS commanded','Fontsize',11);
ylim([0 maxlag*1.5])
title('delay at zeros in ms')
%fig_lag_cycle_percent=figure('Name','lag_cycle_percent');

lag_cycle=(lag_ana_vs_unforcedcps/1000)*f_nat;
yyaxis left

ylabel('percent of cycle','Color','k','FontSize',16)
xlim([0 maxylim])
ylim([0 maxlag/1000*f_nat*1.5*100])
title('delay between solutions at zeros','FontSize',16)

%% Amplitude at maxes comparison plot 
fig_amp_max=figure('Name','fig_amp_max')
ampratio_com_v_enc=amplitude_ratio_code(Commanded_and_measured_position(:,2)/x_0,Commanded_and_measured_position(:,3)/x_0);
ampratio_ana_v_unforced=amplitude_ratio_code(analyt',cps_f_zero');
ampratio_ana_v_com=amplitude_ratio_code(analyt',Commanded_and_measured_position(:,2)/x_0);
ampratio_ana_v_enc=amplitude_ratio_code(analyt',Commanded_and_measured_position(:,3)/x_0);

plot(0.5:0.5:((size(ampratio_ana_v_unforced)/2)),ampratio_ana_v_unforced,'-*','Color', [0 0.4470 0.7410])
hold on;
plot(0.5:0.5:((size(ampratio_ana_v_com,1)/2)),ampratio_ana_v_com,'-*','Color',[0.4940 0.1840 0.5560])
plot(0.5:0.5:((size(ampratio_ana_v_enc,1)/2)),ampratio_ana_v_enc,'-*','Color',[0.8500 0.3250 0.0980])
plot(0.5:0.5:((size(ampratio_com_v_enc,1)/2)),ampratio_com_v_enc,'-*','Color',[0.9290 0.6940 0.1250])
xlim([0 maxylim])
ylim([0 1.5])
xlabel('cycles','FontSize',16)
ylabel('ratio','FontSize',16)
legend('analytical vs unforced virtual cps','analytical vs CPS commanded','analytical vs CPS measured','CPS measured vs CPS commanded','Fontsize',11,'Location','southwest');
title('amplitude ratio between solutions at extrema','FontSize',16)

%%
import mlreportgen.report.*
import mlreportgen.dom.*

saveas(fig_error,trial_name+'-position_plot.png');
impath=which(trial_name+"-position_plot.png");
img1=Image(impath);
img1.Width="2.92in";
img1.Height="2.09in";

saveas(fig_forces,trial_name+'-forces_plot.png');
impath2=which(trial_name+"-forces_plot.png");
img2=Image(impath2);
img2.Width="4in";
img2.Height="3in";

saveas(fig_diff,trial_name+"-difference_plot.png");
impath3=which(trial_name+'-difference_plot.png');
img3=Image(impath3);
img3.Width="2.92in";
img3.Height="2.09in";

saveas(fig_lag,trial_name+"-lag_plot.png");
impath4=which(trial_name+'-lag_plot.png');
img4=Image(impath4);
img4.Width="2.92in";
img4.Height="2.09in";

saveas(fig_amp_max,trial_name+"-amp_plot.png");
impath5=which(trial_name+'-amp_plot.png');
img5=Image(impath5);
img5.Width="2.92in";
img5.Height="2.09in";