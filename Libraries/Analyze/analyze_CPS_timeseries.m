% clear all; 
close all;

trialstart = 1;
trialstotal = 0 + trialstart;

error_meanabs_trial = zeros(trialstotal,1);
error_meanabsrel_trial = zeros(trialstotal,1);
mass_trials = zeros(trialstotal,1);
dampingratio_trials = zeros(trialstotal,1);
freqnat_trials = zeros(trialstotal,1);


for trial = trialstart:trialstotal
disp(['Analyzing trial ',num2str(trial),'...'])
% load(['R:\ENG_Breuer_Shared\jnewbolt\CPS code\Data\2022_1Spring\' ...
%     '20220214_CPSerrorTest_noCylwAccmeterwFilter_',num2str(trial)])
% load(['R:\ENG_Breuer_Shared\jnewbolt\CPS code\Data\2022_1Spring\' ...
%     '20220216_CPSerrorTest_noCylwAccmeterwFilter_',num2str(trial)])


% D = 0.0508; span = 0.4318; mass_disp = 0.875;  
D = 0.054; span = 0.5; mass_disp = pi*(D/2)^2*span*1000;

% Rename data from trial
    time = Heave.time(:);
    timesteps = size(time,1);
    heave_commanded = [Heave.signals.values(:,1)];
    heave = Heave.signals.values(:,2);
    force_y = LateralForce.signals.values(:,1);
    inertialload_y = LateralForce.signals.values(:,2);
    force_y_corrected_filtered = LateralForce.signals.values(:,3);
    
%     % Filter 4th order Butterworth on force data   
%     [b,a] = butter(4,10*T*2); % butter(order,cutofffreq/nyquistfreq)
%     trueforce_y_filtered = filter(b,a,force_y+inertialload_y);    

% Parameters from trial
    u = abs(mean(FlowSpeed.signals.values(:,1)));
    c_vals = damping.signals.values(1);
    k_vals = stiffness.signals.values(1);
    f_natural = 1/(2*pi)*sqrt(k_vals/M);
    Re = u*D*10^6;
    zeta = c_vals/(2*sqrt(k_vals*M));
    f_nyquist = 0.5/T;

    mass_trials(trial) = M;
    dampingratio_trials(trial) = zeta;
    freqnat_trials(trial) = f_natural;
    
% Heave amplitude for the latter half of each trial segment
    heave_max = max(heave(end/2:end));
    heave_min = min(heave(end/2:end));
    heave_ampl = (heave_max - heave_min)/2;
%     heave_ampl(n) = rms(heave(end/2:end));
    heave_ampl_vec = repmat(heave_ampl,[1,size(time)]);
    u_star = 2*pi*u*sqrt(M)/(D*sqrt(k_vals));

% heave spectrum
    duration = max(time)/T;
    heave_hilbert =  hilbert(heave);
    [heave_powerspec,f_heave] = pwelch(heave_hilbert,duration,0,[],1/T);
    [max_power,max_index] = max(10*log10(heave_powerspec));
    f_dom = f_heave(max_index);
    
% force spectrum
    force_hilbert =  hilbert(force_y);
    [force_powerspec,f_force] = pwelch(force_hilbert,duration,0 ,[],1/T);
    [max_power,max_force_index] = max(10*log10(force_powerspec));
    f_force_dom = f_force(max_force_index);

 % force corrected+filtered spectrum
    force_filtered_hilbert =  hilbert(force_y_corrected_filtered);
    [force_filtered_powerspec,f_force_filtered] = pwelch(force_filtered_hilbert,duration,0 ,[],1/T);
    [max_power,max_force_index] = max(10*log10(force_filtered_powerspec));
    f_force_filtered_dom = f_force(max_force_index);   


    % Error compared to exact solution
    exact = oscillator_exact_solution(M,c_vals(1),k_vals(1),heave(1),0,time);
    error_exact = heave-exact;
    [y_simulation,t_simulation] = OscillatorSimulation(mass_trials(trial),dampingratio_trials(trial),f_natural,heave(1),0,T,sim_time);
    error_sim = heave-y_simulation;
    error_meanabs = zeros(timesteps,1);
    for i=1:timesteps
    error_meanabs(i) = sum(abs(error_exact(1:i)))/i;
    end

    % Mean absolute error for each trial
    error_meanabs_trial(trial) = sum( abs(error_exact))/timesteps;
    % Mean absolute error normalized with mean absolute heave
    error_meanabsrel_trial(trial) = (sum( abs( error_exact))/sum(abs(exact)));
    disp(['Error mean absolute relative is ',num2str(error_meanabsrel_trial(trial))])

%% Figure plotting


    % Plot heave and force time series
    figure;
    hold on;
    grid on;
        
%         plot([time(1) time(1)],[-6 6],'Color','red')

%     plot(time,heave,'Color','blue')
%     plot(time,heave_ampl_vec,'Color','red')
%     plot(time,-heave_ampl_vec,'Color','red')
%     plot(time,force_y,'Color','black')

%     [hAx,hLine1,hLine2] = plotyy(time,heave,time,force_y);
%     [hAx,hLine1,hLine2] = plotyy(time, heave,time,inertialload_y);
%     [hAx,hLine1,hLine2] = plotyy(time, heave,time,heave_commanded);


    [hAx,hLine1,hLine2] = plotyy(time, heave,time,force_y_corrected_filtered);
    xlabel('Time (seconds)')
    ylabel(hAx(1),'Heave (cm)')
    ylim(hAx(1),[-6 6]); yticks(hAx(1),[-6:6]);
    ylabel(hAx(2),'Lateral force (N)')
    ylim(hAx(2),[-6 6]); yticks(hAx(2),[-6:6]);
    set(hAx,{'ycolor'},{'b';'r'})
    set(hLine1,'Color','b'); set(hLine2,'Color','r');


% Plot heave and heave error
        figure;
        hold on;
        grid on;
        plot(time,heave_commanded,'Color','cyan','DisplayName','Heave command');
%         plot(time,error,'Color','magenta','DisplayName','Error');
%         plot(time,error_meanabs,'Color','green','DisplayName','Mean absolute error');
        plot(time,heave,'Color','blue','DisplayName','Heave measured');
%         plot(time,exact,'LineStyle',':','Color','red','DisplayName','Exact solution')
        plot(t_simulation,y_simulation,'LineStyle',':','Color','red','DisplayName','Simulated solution')
    %     plot(time,zeros(1,size(time,1)),'Color','black') % Thick line at heave=0
        legend()
        xlabel('Time (s)')
        ylabel('Heave (cm)')
    
        title(['CPS ring down, simulated: m = ',num2str(M),' kg, f_{natural} = ',num2str(f_natural),' Hz, \zeta = ',num2str(zeta)]);
    %             title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u,2) ...
    %         ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
        
    
        hold off;

    % Plot force data

            figure;
        hold on;
        grid on;
    
    
        plot(time,force_y,'Color','cyan','DisplayName','Force lateral');
        plot(time,inertialload_y,'Color','magenta','DisplayName','Force inertial')
%         plot(time,trueforce_y_filtered,'Color','blue','DisplayName','Force corrected+filtered');
        plot(time,force_y_corrected_filtered,'Color','blue','DisplayName','Force corrected & filtered');
        legend();
        xlabel('Time (s)')
        ylabel('Force (N)')
    
        title(['CPS ring down, simulated: m = ',num2str(M),' kg, f_{natural} = ',num2str(f_natural),' Hz, \zeta = ',num2str(zeta)]);
    
    
        hold off;

    % plot welch transform spectrum
           
    % Plot heave spectrum
    figure
    hold on; grid on;
    plot([f_dom f_dom],[-60 30],'Color','red','DisplayName','Frequency dominant');
%     plot([f_nyquist,f_nyquist],[-60,30],'Color','black');
%     plot(f_heave,10*log10(heave_powerspec));
    plot(f_force,10*log10(force_powerspec),'Color','cyan','DisplayName','Force spectrum'); % plot force spectrum
    plot(f_force_filtered,10*log10(force_filtered_powerspec),'Color','blue','DisplayName','Force corrected+filtered spectrum'); % plot force spectrum
    xlabel('Frequency (Hz)')
    ylabel('Power (dB/Hz)')
    xlim([0 20]) 
    ylim([-60 0])
    legend()
    title(['CPS ring down, simulated: m = ',num2str(M),' kg, f_{natural} = ',num2str(f_nat),' Hz, \zeta = ',num2str(zeta)]);
    hold off





end
% 
% % Plot heave errors for different trials 20220223
%     figure(1)
%     hold on; grid on;
%     plot(mass_trials(1:9:trialstotal),error_meanabsrel_trial(1:9:trialstotal),'o','DisplayName','1')
%     plot(mass_trials(2:9:trialstotal),error_meanabsrel_trial(2:9:trialstotal),'o','DisplayName','2')
%     plot(mass_trials(3:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(4:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(5:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(6:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(7:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(8:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     plot(mass_trials(9:9:trialstotal),error_meanabsrel_trial(3:9:trialstotal),'o','DisplayName','3')
%     xlabel('Mass simulated (kg)')
%     ylabel('Error absolute mean relative')
%     legend()
%     title(['CPS ring down, simulated: m = ',num2str(M),' kg, f_{natural} = ',num2str(f_nat),' Hz, \zeta = ',num2str(zeta)]);
% %     hold off