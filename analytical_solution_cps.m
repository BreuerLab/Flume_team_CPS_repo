%% Analytical solution
% post setting the mass (M), spring constant (k), and damping (c) in CPS
% parameters you can use this code to determine the analytical solution for
% the motion of the heave given an offset of x_0
total_time=10;
omega_n=(k/M)^0.5;
xi=c/((k*M)^.5);
omega_d=omega_n*(1-xi^2)^0.5; %omega d is just omega n and xi 
x_0=5;%start_position_cm;
i=[0:T:total_time];
n=0;
x=zeros(1,size(i,2));

tim=[0:T:10];
root=roots([M c k]);
c1=start_position_cm;
if(isreal(root)==0) %complex
    a=real(root(1));
    b=imag(root(1));
    c2=-a*c1/b;
    sol=exp(a.*tim).*(c1.*cos(b.*tim)+c2.*sin(b.*tim));
elseif(root(1)~=root(2)) %distinct
    c2=-c1*root(1)/root(2);    
    sol=c1.*exp(root(1).*tim)+c2.*exp(root(2).*tim);
elseif(root(1)==root(2)) %repeated roots
    c2=-c1*root(1);
    r1=root(1);
    sol=exp(root(1).*tim).*(c1+c2.*tim);
end
analyt=sol/start_position_cm;
%%
plot(tim*((k/M)^0.5)/(2*pi),sol/start_position_cm);
hold on;
cps_f_zero=(Heave_of_ideal_CPS_cm(:,2)/start_position_cm)';
plot((i*omega_n)/(2*pi),cps_f_zero);
legend('analytical','unforced cps');
ylabel('x/x_0');
xlabel('t*sqrt((k/M))/2pi')