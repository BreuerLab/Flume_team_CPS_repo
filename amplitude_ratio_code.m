function ratioamp= amplitude_ratio_code(firstcurve, secondcurve)
%%
% firstcurve =Commanded_and_measured_position(:,2)/x_0;
% secondcurve= Commanded_and_measured_position(:,3)/x_0;

extrema_firstcurve_index=find(islocalmax(firstcurve)+islocalmin(firstcurve));
extrema_secondcurve_index=find(islocalmax(secondcurve)+islocalmin(secondcurve));
%%
if size(extrema_firstcurve_index,1)<size(extrema_secondcurve_index,1)
    extrsize=size(extrema_firstcurve_index,1);
else
    extrsize=size(extrema_secondcurve_index,1);
end

extrema_firstcurve=firstcurve(extrema_firstcurve_index);
extrema_secondcurve=secondcurve(extrema_secondcurve_index);
%%
ratioamp=extrema_firstcurve(1:extrsize-1,1)./extrema_secondcurve(1:extrsize-1,1);
%%

end