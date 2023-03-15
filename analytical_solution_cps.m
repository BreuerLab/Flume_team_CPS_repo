%% Analytical solution
% post setting the mass (M), spring constant (k), and damping (c) in CPS
% parameters you can use this code to determine the analytical solution for
% the motion of the heave given an offset of x_0
total_time=duration_sim;
x_0=Commanded_and_measured_position(1,3); %start_position_cm;
i=[0:T:total_time];
n=0;
x=zeros(1,size(i,2));
omega_n=(k/M)^0.5;

tim=[0:T:total_time];
root=roots([M c k]);
c1=x_0;
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
analyt=sol/x_0;
%plot(tim*((k/M)^0.5)/(2*pi),sol/x_0);