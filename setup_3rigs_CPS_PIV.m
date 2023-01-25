% function daq_setup_3rigs_CPS_PIV
% ARPA-e Pitch Heave Device Session Based Data Aquisition Setup
%   rate: data scans per second
%EDITED 2023/01/19 by Eva Erickson for MATLAB R2022a
global s last_out pitch_bias run_num piv_var chord span foil_shape Wall_distance_right Wall_distance_left...
    flume_height flume_hertz foil_separation foil_offset Temperature Number_of_foils pitch_axis fname exp_name
pitch_bias = [0 0 0];
%% Experimental Setup

prompt = {'Enter chord size (in meters): ','Enter span (in meters): ','Enter foil shapes (as string): ',...
    'Enter Mean wall distance (left, in meters): ','Enter Mean wall distance (right, in meters): ','Enter Flume water height(in meters): ',...
    'Enter anticipated flume frequency (Hz): ','Enter number of foils in experiment: ','Enter foil separation distance (m): ','Enter foil offset distance (m): ',...
    'Enter flume water temperature (from vectrino, in c):   ','Enter foil Pitch Axis','Using PIV? (enter 1 for yes)','Enter Experiment name (folder Name):'};
name = 'Experiment Configuration';
num_lines = 1;
defaultanswer = {'0.0508','0.4318','cylinder','0.4','0.4','0.505','14.5','1','0','0','20.85','0.5','0','Enter descriptive name'};
answer = inputdlg(prompt,name,num_lines,defaultanswer);


chord = str2num(answer{1});
span = str2num(answer{2});
foil_shape = answer(3);
Wall_distance_left = str2num(answer{4});
Wall_distance_right = str2num(answer{5});
flume_height = str2num(answer{6});
flume_hertz = str2num(answer{7});
Number_of_foils = str2num(answer{8});
foil_separation = str2num(answer{9});
foil_offset = str2num(answer{10});
Temperature = str2num(answer{11});
pitch_axis = str2num(answer{12});
piv_var = str2num(answer{13});
fname = ['R:\ENG_Breuer_Shared\group\Eva\testing\',answer{14}];
exp_name = answer{14};
Date  = date;
Time = clock;

if isfolder(fname)
    disp('Warning: experiment name already exists.  Apppending date and time')
    fname = [fname,'_',Date,'_',num2str(Time(4)),'_',num2str(Time(5)),'_',num2str(round(Time(6)))];
    if isfolder(fname)
        disp('Warning: folder name still taken. Appending time')
        fname = [fname,'_',num2str(Time(4)),'_',num2str(Time(5)),'_',num2str(Time(6))];
    end
end

mkdir([fname,'\data'])

% copyfile('C:\Users\ControlSystem\Documents\vertfoil\Control_code\', [fname,'\code'])


disp(['Initialized folder:',fname])
disp('Checking velocimeters')
V(1) = system('tasklist /FI "IMAGENAME eq vectrino.exe" 2>NUL | find /I /N "vectrino.exe">NUL','-echo');
V(2) = system('tasklist /FI "IMAGENAME eq vector.exe" 2>NUL | find /I /N "vector.exe">NUL','-echo');

if V(1)
%     system('C:\Nortek\Vectrino\Vectrino.exe')
    disp('Open Vectrino.exe. Start Vectrino in software.  Start data recording as well.')
end
if V(2)
%     system('C:\Nortek\Vector\Vector.exe')
    disp('Open Vector.exe. Start Vector in software.  Start data recording as well.')
else
    disp('ensure Vectrino and Vector are collecting data and recording to file')
end

%% Establish DAQ Channels to use (this could be made into a seperate script like setup_DAQ_channels)

disp('Inititializing NI DAQs')

% Channels in s are as follows:
% 
% Data acquisition session using National Instruments hardware:
%    No data queued.  Will run at 1000 scans/second.
%    Number of channels: 28
%       index Type Device Channel   MeasurementType        Range         Name   
%       ----- ---- ------ ------- ------------------- ---------------- ---------
%       1     ci   Dev1   ctr3    Position            n/a              Pitch 1
%       2     ci   Dev1   ctr2    Position            n/a              Heave 1
%       3     ci   Dev1   ctr1    Position            n/a              Pitch 2
%       4     ci   Dev1   ctr0    Position            n/a              Heave 2
%       5     ci   Dev2   ctr0    Position            n/a              Pitch 3
%       6     ci   Dev2   ctr1    Position            n/a              Heave 3
%       7     ai   Dev1   ai0     Voltage (Diff)      -10 to +10 Volts Wallace 1
%       8     ai   Dev1   ai1     Voltage (Diff)      -10 to +10 Volts Wallace 2
%       9     ai   Dev1   ai2     Voltage (Diff)      -10 to +10 Volts Wallace 3
%       10    ai   Dev1   ai3     Voltage (Diff)      -10 to +10 Volts Wallace 4
%       11    ai   Dev1   ai4     Voltage (Diff)      -10 to +10 Volts Wallace 5
%       12    ai   Dev1   ai5     Voltage (Diff)      -10 to +10 Volts Wallace 6
%       13    ai   Dev1   ai6     Voltage (SingleEnd) -10 to +10 Volts Vel_x
%       14    ai   Dev1   ai14    Voltage (SingleEnd) -10 to +10 Volts Vel_y
%       15    ai   Dev1   ai7     Voltage (SingleEnd) -10 to +10 Volts Vel_z1
%       16    ai   Dev1   ai15    Voltage (SingleEnd) -10 to +10 Volts Vel_z2
%       17    ai   Dev1   ai16    Voltage (Diff)      -10 to +10 Volts Gromit 1
%       18    ai   Dev1   ai17    Voltage (Diff)      -10 to +10 Volts Gromit 2
%       19    ai   Dev1   ai18    Voltage (Diff)      -10 to +10 Volts Gromit 3
%       20    ai   Dev1   ai19    Voltage (Diff)      -10 to +10 Volts Gromit 4
%       21    ai   Dev1   ai20    Voltage (Diff)      -10 to +10 Volts Gromit 5
%       22    ai   Dev1   ai21    Voltage (Diff)      -10 to +10 Volts Gromit 6
%       23    ao   Dev1   ao2     Voltage (SingleEnd) -10 to +10 Volts Pitch 1
%       24    ao   Dev1   ao0     Voltage (SingleEnd) -10 to +10 Volts Heave 1
%       25    ao   Dev1   ao3     Voltage (SingleEnd) -10 to +10 Volts Pitch 2
%       26    ao   Dev1   ao1     Voltage (SingleEnd) -10 to +10 Volts Heave 2
%       27    ao   Dev2   ao0     Voltage (SingleEnd) -10 to +10 Volts Pitch 3
%       28    ao   Dev2   ao1     Voltage (SingleEnd) -10 to +10 Volts Heave 3

s=daq("ni");
s.Rate= 1000;%2000; %sample rate
T=1/s.Rate;

pitch_axis = 0.5; 

%% Counter channels for encoder inputs

ch1=addinput(s,"Dev3","ctr0","Position");
ch1.EncoderType='X4';
ch1.ZResetEnable=0;
ch1.Name = 'Pitch Shawn';
ch1.ZResetCondition = 'BothLow';
ch1.ZResetValue= -65;

ch2=addinput(s,'Dev3','ctr1','Position');
ch2.EncoderType='X4';
ch2.ZResetEnable=0;
ch2.Name = 'Heave Shawn';
ch2.ZResetCondition = 'BothLow';
ch2.ZResetValue = 0;

ch3=addinput(s,"Dev2","ctr3","Position");
ch3.EncoderType='X4';
ch3.ZResetEnable=0;
ch3.ZResetCondition = 'BothLow';
ch3.Name = 'Pitch Gromit';
ch3.ZResetValue = -795;

ch4=addinput(s,"Dev2","ctr2","Position");
ch4.EncoderType='X4';
ch4.ZResetEnable=0;
ch4.ZResetCondition = 'BothLow';
ch4.ZResetValue = 0;
ch4.Name = 'Heave Gromit';

ch5=addinput(s,"Dev2","ctr1","Position");
ch5.EncoderType='X4';
ch5.ZResetEnable=0;
ch5.ZResetCondition = 'BothLow';
ch5.Name = 'Pitch Wallace';
ch5.ZResetValue = 338;

ch6=addinput(s,"Dev2","ctr0","Position");
ch6.EncoderType='X4';
ch6.ZResetEnable=0;
ch6.ZResetCondition = 'BothLow';
ch6.ZResetValue = 0;
ch6.Name = 'Heave Wallace';

% s.addTriggerConnection('Dev1/PFI12','Dev4/PFI0','StartTrigger');
% s.addClockConnection('Dev1/PFI14','Dev4/PFI14', 'ScanClock');

disp('Counters done!')

%% Analog input channels

global chins1 chins2 chins3 chins4 chins6
chins1=addinput(s,'dev2',[0 1 2 3 4 5 ],'Voltage'); %wallace force sensor (according to setup_DAQ_channels)
chins2=addinput(s,'dev3',[6 7 8 9],'Voltage');
chins3=addinput(s,'dev3',[0 1 2 3 4 5],'Voltage');
% no 4 in DAQ, chins4=addinput('dev2',[22 23],'Voltage'); % analog pitch and heave (15 + 7 = 22 all analog inputs from board 1 + position on board 2)
chins6=addinput(s,'dev2',[24],'Voltage'); % accelerometer and empty DAC channel

chins1(1).Name = 'Wallace 1';
chins1(2).Name = 'Wallace 2';
chins1(3).Name = 'Wallace 3';
chins1(4).Name = 'Wallace 4';
chins1(5).Name = 'Wallace 5';
chins1(6).Name = 'Wallace 6';


chins2(1).TerminalConfig='SingleEnded';
chins2(1).Name = 'Vel_x';
chins2(2).TerminalConfig='SingleEnded';
chins2(2).Name = 'Vel_y';
chins2(3).TerminalConfig='SingleEnded';
chins2(3).Name = 'Vel_z1';
chins2(4).TerminalConfig='SingleEnded';
chins2(4).Name = 'Vel_z2';


chins3(1).Name = 'Gromit 1';
chins3(2).Name = 'Gromit 2';
chins3(3).Name = 'Gromit 3';
chins3(4).Name = 'Gromit 4';
chins3(5).Name = 'Gromit 5';
chins3(6).Name = 'Gromit 6';

chins4(1).Name = 'Trigger';

chins6(1).Name = 'Accelerometer';
chins6(1).TerminalConfig='SingleEnded';

disp('Analog inputs done.')

%% Outputs 
chout1 = addoutput(s,'dev3','ao0','Voltage');  % Pitch 1   Shawn
chout2 = addoutput(s,'dev3','ao1','Voltage');  % Heave 1   Shawn
chout3 = addoutput(s,'dev2','ao2','Voltage');  % Pitch    Gromit
chout4 = addoutput(s,'dev2','ao3','Voltage');  % Heave   Gromit
chout5 = addoutput(s,'dev2','ao0','Voltage');  % Pitch  Wallace
chout6 = addoutput(s,'dev2','ao1','Voltage');  % Heave  Wallace

chout1.Name = 'Pitch Shawn';
chout2.Name = 'Heave Shawn';
chout3.Name = 'Pitch Gromit';
chout4.Name = 'Heave Gromit'; 
chout5.Name = 'Pitch Wallace';
chout6.Name = 'Heave Wallace';
disp('Analog outputs done. Syncing and Zeroing output...')

% PIV trigger and pulse train channels
    addoutput(s,'dev2','Port0/line14','Digital');% output a trigger signal to the PTU, Dev2.2, P0.5
    addinput(s,'dev2','Port0/line10','Digital'); % record the trigger signal, Dev2.2, P0.1
    addinput(s,'dev2','Port0/line9','Digital'); % record the pulse signal from the PTU, Dev2.2, P0.0


% addTriggerConnection(s,'Dev1/PFI4','Dev4/PFI0','StartTrigger');
% 
% s.addClockConnection('Dev1/PFI5','Dev4/PFI1','ScanClock');

% addTriggerConnection(s,'/Dev2/RTSI0','/Dev1/RTSI0','StartTrigger');
% addTriggerConnection(s,'/Dev2/RTSI0','/Dev3/RTSI0','StartTrigger');
% addClockConnection(s,'/Dev2/RTSI1','/Dev1/RTSI1','ScanClock');
% addClockConnection(s,'/Dev2/RTSI1','/Dev3/RTSI1','ScanClock');
% % 
% addTriggerConnection(s,'/Dev3/20MHzTimebase','/Dev1/PFI6','StartTrigger');
% addTriggerConnection(s,'/Dev3/PFI14','/Dev2/PFI14','StartTrigger');
% addClockConnection(s,'/Dev3/PFI15','/Dev1/PFI5','ScanClock');
% addClockConnection(s,'/Dev3/PFI15','/Dev2/PFI15','ScanClock');
% % 
% t1 = addTriggerConnection(s,'/Dev3/PFI14','/Dev1/PFI6','StartTrigger');
% t2 = addTriggerConnection(s,'/Dev3/PFI14','/Dev2/PFI14','StartTrigger');
% c1 = addClockConnection(s,'/Dev1/PFI5','/Dev2/PFI15','ScanClock');
% c2 = addClockConnection(s,'/Dev1/PFI5','/Dev3/PFI15','ScanClock');

last_out = [0 0 0 0 0 0 0];
  write(s,last_out)




% chord = input('Enter chord size (in meters):   ');
% span = input('Enter span (in meters):   ');
% foil_shape = input('Enter foil shapes (as string):   ');
% Wall_distance_left = input('Enter Mean wall distance (in meters):   ');
% Wall_distance_right = input('Enter Mean wall distance (in meters):   ');
% flume_height = input('Enter Flume water height(in meters):   ');
% flume_hertz = input('Enter anticipated flume frequency (Hz):  ');
% foil_separation = input('Enter foil separation distance (m):   ');
% foil_offset = input('Enter foil offset distance (m):   ');
% Temperature = input('Enter flume water temperature (from vectrino, in c):   ');



% d = datevec(date);
% DIR = sprintf('C:\\Users\\Control Systems\\Documents\\vert_foil\\Data\\3rigs\\%02i_%02i\\',d(2),d(3));
% if exist(DIR,'dir')==7
%     run_num = numel(dir([DIR,'run*']))+1;
% else
% mkdir(DIR);
% end
save([fname,'\Exp_config'],'answer');
disp('All set');%. Turn on motor power. Press any key to run find_bias_3rigs');
% find_bias_3rigs;

% disp('Run flume.  Click <a href="matlab: find_zero_pitch">find_zero_pitch</a> when at full speed.')

