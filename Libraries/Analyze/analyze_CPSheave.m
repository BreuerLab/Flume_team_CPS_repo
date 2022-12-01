% this script analyzes the heaving data for a single cylinder
close all;
load('Data\2022_1Spring\20220316_CPS_CylinderPowerCoef_1.mat')

% trial_time = sim_time/(2*steps);
trial_time = sim_time/(steps);
period = trial_time/T; % trial time times sampling rate
periods = sim_time/trial_time; % Number of different parameter sets used

D = 0.054;
span = 0.447;
mass_disp = 1000*pi*(D/2)^2*span;


heave_ampl = zeros(1,periods);
c_vals = zeros(1,periods);
k_vals = zeros(1,periods);
u_star = zeros(1,periods);
phaselag = zeros(1,periods);
u = zeros(1,periods);
Re = zeros(1,periods);
f_dom = zeros(1,periods);
f_star = zeros(1,periods);
f_natural = zeros(1,periods);
% force_y =  LateralForce.signals.values(:,1);



for n = 1:periods
% for n = 6:10
    start = (n-1)*period+1;
    finish = n*period;
    time = Heave.time(start:finish);
    heave = Heave.signals.values(start:finish,2);
    force_y = LateralForce.signals.values(start:finish,1);
    
%     % lowpass filter for force data
%     
%     filtdesn = designfilt('lowpassfir', ...
%     'SampleRate',1/T, ...
%     'PassbandFrequency',3,'StopbandFrequency',4, ...
%     'PassbandRipple',1,'StopbandAttenuation',60, ...
%     'DesignMethod','kaiserwin');
%     force_y_fltr = filtfilt(filtdesn,force_y);
%     phaselag(n) = mod(finddelay(heave,force_y_fltr),1/T);
    
    u(n) = abs(mean(FlowSpeed.signals.values(start+period/2:finish,1)));
%     u(n) = abs(mean(FlowSpeed.signals.values(:,1)));
    c_vals(n) = damping.signals.values(start+period/2);
    k_vals(n) = stiffness.signals.values(start+period/2);
    zeta(n) = c_vals(n)/(2*sqrt(k_vals(n)*M));
    f_natural(n) = 1/(2*pi)*sqrt(k_vals(n)/M);
    Re(n) = u(n)*D*10^6;
    

    % heave amplitude for the latter half of each segment
    heave_max = max(heave(end/2:end));
    heave_min = min(heave(end/2:end));
    heave_ampl(n) = (heave_max - heave_min)/2;
%     heave_ampl(n) = rms(heave(end/2:end));
    heave_ampl_vec = repmat(heave_ampl(n),[1,size(time)]);
    u_star(n) = 2*pi*u(n)*sqrt(M)/(D*sqrt(k_vals(n)));


    figure(1)
    hold on
        
        plot([time(1) time(1)],[-6 6],'Color','red')
    plot(time,heave,'Color','blue')
%     plot(time,force_y,'Color','black')
%     plot(time,force_y_fltr,'Color','red')
    plot(time,heave_ampl_vec,'Color','red')
    plot(time,-heave_ampl_vec,'Color','red')
        plot(time,zeros(1,size(time,1)),'Color','green')
    xlabel('Time (seconds)')
    ylabel('Heave (cm)')
    title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
    hold off
    
    % plot hilbert transform spectrum
%     

    heave_hilbert =  hilbert(heave);
    [heave_powerspec,f] = pwelch(heave_hilbert,period/4,0,[],1/T);
    [max_power,max_index] = max(10*log10(heave_powerspec));
    f_dom(n) = f(max_index);
    f_star(n) = D*f_dom(n)./u(n);

%     figure(2)
%     hold on
%     plot(f,10*log10(heave_powerspec));
% %     legend('Original','hilbert')
%     xlabel('Frequency (Hz)')
%     ylabel('Power (dB/Hz)')
%     xlim([-1 10]) 
%     ylim([-50 50])
%     hold off

end

heave_ampl_ND = heave_ampl/(100*D);
zeta = c_vals(n)/(2*sqrt(k_vals(n)*M));
    

%     figure(2)
%     plot([1:periods],c_vals)
%     figure(3)
%     plot([1:periods],k_vals)
%     figure(4)
%     plot([1:periods],u_star)

% plot heave amplitude vs. u*

    fig5 = figure(5);
    fig5.Position = [50 50 1000 500]; % lower left x and y, width and height
    hold on
    plot(u_star(1:periods/2),heave_ampl_ND(1:periods/2),'Marker','^','LineWidth',3)
    plot(u_star(periods/2+1:periods),heave_ampl_ND(periods/2+1:periods),'Marker','v','LineWidth',3)
    plot(5*[1 1],[0 10],'Color','red')
    hold off
    grid on
    xlabel('U* = U/D f_N')
    ylabel('A* = y_0/D')
    xlim([1 11])
    ylim([0 1.2])
    % Title for constant U, varying damping and stiffness
    title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
    % Title for varying U, constant damping and stiffness
%     title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', c = ' num2str(c_vals(1),3) ...
%         ' kg/s, k = ' num2str(k_vals(1),3) ' N/m, D = ' num2str(100*D,2) ...
%         ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ' to ' num2str(Re(periods/2),2) ' )'])
    
% plot heave amplitude vs. U/D*f_measured

    fig5 = figure(5);
    fig5.Position = [50 50 1000 500]; % lower left x and y, width and height
    hold on
%     u_star_fdom = u_star.*f_natural./f_dom;
%     plot(u_star_fdom(1:periods/2),heave_ampl_ND(1:periods/2),'Marker','^','LineWidth',3)
%     plot(u_star_fdom(periods/2+1:periods),heave_ampl_ND(periods/2+1:periods),'Marker','v','LineWidth',3)
    plot(f_star(1:periods),heave_ampl_ND(1:periods),'Marker','^','LineWidth',3)
    plot(5*[1 1],[0 10],'Color','red')
    hold off
    grid on
%     xlabel('U* = U/D f_{meas}')
    xlabel('f* = D f_{meas}/U')
    ylabel('A* = y_0/D')
    xlim([0.1 0.3])
    ylim([0 1.2])
    % Title for constant U, varying damping and stiffness
    title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
    % Title for varying U, constant damping and stiffness
%     title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', c = ' num2str(c_vals(1),3) ...
%         ' kg/s, k = ' num2str(k_vals(1),3) ' N/m, D = ' num2str(100*D,2) ...
%         ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ' to ' num2str(Re(periods/2),2) ' )'])
        

% plot delay between force and heave 

%     figure(6)
%     hold on
%     plot(u_star(1:periods/2),phaselag(1:periods/2),'Marker','^','LineWidth',3)
%     plot(u_star(periods/2+1:periods),phaselag(periods/2+1:periods),'Marker','v','LineWidth',3)
%     hold off
%     grid on
%     xlabel('U* = U/D f_N')
%     ylabel('Phase lag')
%     title(['m* = ' num2str(M) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u,2) ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str(M*zeta,2) ')'])
% 

% plot dominant freq of heave response

    f_dom_star = f_dom./f_natural;
    f_St_star = 0.2*u./(D*f_natural);
    figure(7)
    hold on
    plot(u_star(1:periods/2),f_dom_star(1:periods/2),'Marker','^','LineWidth',3)
    plot(u_star(periods/2+1:periods),f_dom_star(periods/2+1:periods),'Marker','v','LineWidth',3)
    plot((0:1:15),ones(1,16)); 
    plot([0 u_star(1:periods/2) 15],[0 f_St_star(1:periods/2) 0.2*15]);
    hold off
    grid on
    xlim([0 12])
    ylim([0 3])
    xlabel('U* = U/D f_N')
    ylabel('f_{dominant}/f_{spring}')
    title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
  
