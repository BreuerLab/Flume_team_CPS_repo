% this script analyzes the heaving data for a single cylinder
close all;
trial_time = 30; T = 1/2000;
duration = trial_time/T; % trial time times sampling rate
trials = 1; % Number of different parameter sets used

D = 0.054; span = 0.50; mass_disp = 1000*pi*(D/2)^2*span;

set(0,'defaultAxesFontSize',22); set(0,'defaultAxesFontName','Arial');
set(0,'defaultLineLineWidth',2);

% for settings =  4
%     if settings == 1
%         %'w/o cylinder, m = 0.55 kg'
%         trials = 1; %31
%         settings_str = 'Data\2021_3Fall\20211221_RingDown_NoObjectNoFilterNoAccelmeter_';
%         color_str = 'Blue';
%     elseif settings == 2
%         % 'w/ cylinder, m = 1.39 kg' 
%         trials = 17;
%         settings_str = 'Data\2021_3Fall\20211221_RingDown_wCylNoFilterNoAccelmeter_';
%         color_str = 'Red';
%     elseif settings == 3
%         % 'w/ cyl & accelmeter, m = 1.39 kg'
%         trials = 15;
%         settings_str = 'Data\2021_3Fall\20211221_RingDown_wCylNoFilterwAccelmeter_';
%         color_str = 'Green';
%     elseif settings == 4
%         % w/ cyl & filter & accelmeter, m = 1.39 kg
%         trials = 1;
%         settings_str = 'Data\2021_3Fall\20211222_RingDown_wCylwFilterwAccelmeter_';
%         color_str = 'blue';
%     end
%         
    
heave_ampl = zeros(1,trials);
m_vals = zeros(1,trials);
c_vals = zeros(1,trials);
k_vals = zeros(1,trials);
u_star = zeros(1,trials);
phaselag = zeros(1,trials);
u = zeros(1,trials);
Re = zeros(1,trials);
f_dom = zeros(1,trials);
f_dom_star = zeros(1,trials);
f_force_dom = zeros(1,trials);
f_force_dom_star = zeros(1,trials);
f_natural = zeros(1,trials);
    
% for n = 1:trials
%     load([settings_str,num2str(n),'.mat']);

for n = 1:1 % uncomment to analyze a single trial manually loaded, must also comment out 2 lines above
    
    start = 1; finish = duration;
    time = Heave.time(start:finish);
    heave = Heave.signals.values(start:finish,2);
    force_y = LateralForce.signals.values(start:finish,1);
    
%     u(n) = abs(mean(FlowSpeed.signals.values(start+period/2:finish,1)));
%     u(n) = abs(mean(FlowSpeed.signals.values(:,1)));
    u(n) = 0;
    m_vals(n) = M;
    c_vals(n) = damping.signals.values(1);
    k_vals(n) = stiffness.signals.values(1);
    zeta(n) = c_vals(n)/(2*sqrt(k_vals(n)*M));
    f_natural(n) = 1/(2*pi)*sqrt(k_vals(n)/M);
    f_nat_water(n) = 1/(2*pi)*sqrt(k_vals/(M+mass_disp));
    Re(n) = u(n)*D*10^6;
    

    % Heave amplitude for the latter half of each duration
    heave_max = max(heave(end/2:end));
    heave_min = min(heave(end/2:end));
    heave_ampl(n) = (heave_max - heave_min)/2;
%     heave_ampl(n) = rms(heave(end/2:end));
    heave_ampl_vec = repmat(heave_ampl(n),[1,size(time)]);
    u_star(n) = 2*pi*u(n)*sqrt(M)/(D*sqrt(k_vals(n)));

%     figure(1)
%     hold on
%         
%     plot([time(1) time(1)],[-6 6],'Color','red')
%     plot(time,heave,'Color','blue')
%     plot(time,force_y,'Color','black')
%     plot(time,force_y_fltr,'Color','red')
%     plot(time,heave_ampl_vec,'Color','red')
%     plot(time,-heave_ampl_vec,'Color','red')
%     plot(time,zeros(1,size(time,1)),'Color','green')
%     xlabel('Time (seconds)')
%     ylabel('Heave (cm)')
%     title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
%         ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
%     hold off
    
    % plot welch transform spectrum
%     

    heave_hilbert =  hilbert(heave);
    [heave_powerspec,f_heave] = pwelch(heave_hilbert,duration,0,[],1/T);
    [max_power,max_index] = max(10*log10(heave_powerspec));
    f_dom(n) = f_heave(max_index);
    
    force_hilbert =  hilbert(force_y);
    [force_powerspec,f_force] = pwelch(force_hilbert,duration,0 ,[],1/T);
    [max_power,max_force_index] = max(10*log10(force_powerspec));
    f_force_dom(n) = f_force(max_force_index);
            
    figure(2)
    hold on
    plot(f_heave,10*log10(heave_powerspec));
    grid on
%     plot(f_force,10*log10(force_powerspec));
%     legend('Original','hilbert')
    xlabel('Frequency (Hz)')
    ylabel('Power (dB/Hz)')
    xlim([-1 15]) 
    ylim([-60 30])
    hold off

end

heave_ampl_ND = heave_ampl/(100*D);
zeta = c_vals(n)/(2*sqrt(k_vals(n)*M));
    

%     figure(2)
%     plot([1:periods],c_vals)
%     figure(3)
%     plot([1:periods],k_vals)
%     figure(4)
%     plot([1:periods],u_star)

% % plot heave amplitude vs. u*
% 
%     fig5 = figure(5);
%     fig5.Position = [50 50 1000 500]; % lower left x and y, width and height
%     hold on
%     plot(u_star(1:periods/2),heave_ampl_ND(1:periods/2),'Marker','^','LineWidth',3)
%     plot(u_star(periods/2+1:periods),heave_ampl_ND(periods/2+1:periods),'Marker','v','LineWidth',3)
%     plot(5*[1 1],[0 10],'Color','red')
%     hold off
%     grid on
%     xlabel('U* = U/D f_N')
%     ylabel('A* = y_0/D')
%     xlim([1 11])
%     ylim([0 1.2])
%     % Title for constant U, varying damping and stiffness
%     title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
%         ' cm/s, D = ' num2str(100*D,2) ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ')'])
%     % Title for varying U, constant damping and stiffness
% %     title(['m* = ' num2str(M/mass_disp,3) ', \zeta = ' num2str(zeta,2) ', c = ' num2str(c_vals(1),3) ...
% %         ' kg/s, k = ' num2str(k_vals(1),3) ' N/m, D = ' num2str(100*D,2) ...
% %         ' cm (m*\zeta = ' num2str((M/mass_disp)*zeta,2) ', Re = ' num2str(Re(1),2) ' to ' num2str(Re(periods/2),2) ' )'])
%     
    
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
    plot(m_vals,f_dom_star,'Marker','^','Color','g','LineWidth',3)
    plot(m_vals,f_dom_star*sqrt((mass_disp+M)/M),'Marker','^','Color','b','LineWidth',3)    
%     plot(M,f_dom_star(periods/2+1:periods),'Marker','v','LineWidth',3)
%     plot((0:1:15),ones(1,16)); 
%     plot(M,[0 f_St_star(1:periods/2) 0.2*15]);
    hold off
    grid on
    xlim([0 10])
    ylim([0 1.5])
    xlabel('Mass simulated (kg)')
    ylabel('f_{dominant,heave}/f_{spring}')
    title(['CPS ring down, f_{spring} = ' num2str(1,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s'])
%     legend('w/o cylinder, m = 0.55 kg','w/ cylinder, m = 1.39 kg','w/ cyl & accelmeter, m = 1.39 kg');
    
    % plot dominant freq of force response
    
    f_force_dom_star = f_force_dom./f_natural;
    f_St_star = 0.2*u./(D*f_natural);
    figure(8)
    hold on
    plot(m_vals,f_force_dom_star,'Marker','^','Color',color_str,'LineWidth',3)
%     plot(M,f_dom_star(periods/2+1:periods),'Marker','v','LineWidth',3)
%     plot((0:1:15),ones(1,16)); 
%     plot(M,[0 f_St_star(1:periods/2) 0.2*15]);
    hold off
    grid on
    xlim([0 10])
    ylim([0 20])
    xlabel('Mass simulated (kg)')
    ylabel('f_{dominant,force}/f_{spring}')
    title(['CPS ring down, f_{spring} = ' num2str(1,3) ', \zeta = ' num2str(zeta,2) ', U = ' num2str(100*u(n),2) ...
        ' cm/s'])
%     legend('w/o cylinder, m = 0.55 kg','w/ cylinder, m = 1.39 kg','w/ cyl & accelmeter, m = 1.39 kg');

% end

