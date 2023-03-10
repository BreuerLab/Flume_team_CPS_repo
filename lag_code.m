function lag = lag_code(firstcurve,secondcurve)
zeros_firstcurve=[];
zeros_secondcurve=[];

%finding where the zeros are
for index=2:size(firstcurve)
    %commanded zeros
    if firstcurve(index)*firstcurve(index-1)<0
        zeros_firstcurve=[zeros_firstcurve; index];
    end
    %encoder zeros
    if secondcurve(index)*secondcurve(index-1)<0
        zeros_secondcurve=[zeros_secondcurve; index];
    end
end

if size(zeros_firstcurve,1)<size(zeros_secondcurve,1)
    zerolagsize=size(zeros_firstcurve,1);
else
    zerolagsize=size(zeros_secondcurve,1);
end

%%
lag=zeros(zerolagsize-1,1);
lagindex=1;
%finding lag between 2 zeros between commanded and encoder
for index=2:zerolagsize
    pad_zeros=zeros(zeros_secondcurve(index-1)-zeros_firstcurve(index-1),1);
    lag_calc=finddelay(firstcurve(zeros_firstcurve(index-1):zeros_firstcurve(index)),[pad_zeros; secondcurve(zeros_secondcurve(index-1):zeros_secondcurve(index))]);
    lag(lagindex)=lag_calc;
    lagindex=lagindex+1;
end
end