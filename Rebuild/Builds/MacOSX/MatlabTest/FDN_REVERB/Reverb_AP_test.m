
N1 = 347;
N2 = 113;
N3 = 37;
% g = (1-sqrt(q))/(1+sqrt(q));
g=0.55;

APb1 = [-g,zeros(1,N1-1),1];
APb2 = [-g,zeros(1,N2-1),1];
APb3 = [-g,zeros(1,N3-1),1];
APa1 = [1,zeros(1,N1-1),-g];
APa2 = [1,zeros(1,N2-1),-g];
APa3 = [1,zeros(1,N3-1),-g];
filter1 = filter(APb1,APa1,x');
filter2 = filter(APb2,APa2,filter1');
filter3 = filter(APb3,APa3,filter2');










