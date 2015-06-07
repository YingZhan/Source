
%[x,fs] = audioread('Daylight.m4a');
%size(x)
%x = mean(x')';
%size(x)
% x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,45,24,22,34,23,24,25,26,27,28,23,11,99,8,54,34,23,4,3,8,7,5,3,6,89,6,89,43,56,10];

x = ones(1,512);
fs = 44100/4;
f = 1000;
% for i = 1:length(x)
%     x(i) = sin(2*pi * f * i/fs);
% end


N = length(x);
y = zeros(1,N);
b = ones(16,1);
c = [1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1];


f_sine = fopen('FDNDC.txt','w');

m = [919,997,1061,1093,1129,1151,1171,1187,1213,1237,1259,1283,1303,1319,1327,1361];
%g = 0.9;
% delay-line matrix (need to be mutually prime)
% m = [919 997 1061 1093 1129 1151 1171 1187 1213 1237 1259 1283 1303 1319 1327 1361];
% y1.. present signal after delay line 
% it is better to create max(m(i)) of memory, or keep it growing?
y1 = zeros(1,max(m)); 
y2 = zeros(1,max(m));
y3 = zeros(1,max(m));
y4 = zeros(1,max(m));
y5 = zeros(1,max(m));
y6 = zeros(1,max(m));
y7 = zeros(1,max(m));
y8 = zeros(1,max(m));
y9 = zeros(1,max(m));
y10 = zeros(1,max(m));
y11 = zeros(1,max(m));
y12 = zeros(1,max(m));
y13 = zeros(1,max(m));
y14 = zeros(1,max(m));
y15 = zeros(1,max(m));
y16 = zeros(1,max(m));
% x1... present signal before delay line
x1 = zeros(1,N);
x2 = zeros(1,N);
x3 = zeros(1,N);
x4 = zeros(1,N);
x5 = zeros(1,N);
x6 = zeros(1,N);
x7 = zeros(1,N);
x8 = zeros(1,N);
x9 = zeros(1,N);
x10 = zeros(1,N);
x11 = zeros(1,N);
x12 = zeros(1,N);
x13 = zeros(1,N);
x14 = zeros(1,N);
x15 = zeros(1,N);
x16 = zeros(1,N);

%%q = 1.25/3;
%bp = kp*log(10)/80*(1-1/(q*q));


a = 0.5*[1 -1 -1 -1;-1 1 -1 -1;-1 -1 1 -1;-1 -1 -1 1];
a2 = 0.5*[a -a -a -a;-a a -a -a;-a -a a -a;-a -a -a a];


for n = 1:N    
    z1 = [y1(n);y2(n);y3(n);y4(n);y5(n);y6(n);y7(n);y8(n);y9(n);y10(n);y11(n);y12(n);y13(n);y14(n);y15(n);y16(n)];
    %z = [y1(n);y2(n);y3(n);y4(n);y5(n);y6(n);y7(n);y8(n);y9(n);y10(n);y11(n);y12(n);y13(n);y14(n);y15(n);y16(n)]
    y(n) = x(n)+c'*z1;
    x1(n) = [a2(1,:)*z1+x(n)];
    x2(n) = [a2(2,:)*z1+x(n)];
    x3(n) = [a2(3,:)*z1+x(n)];
    x4(n) = [a2(4,:)*z1+x(n)];
    x5(n) = [a2(5,:)*z1+x(n)];
    x6(n) = [a2(6,:)*z1+x(n)];
    x7(n) = [a2(7,:)*z1+x(n)];
    x8(n) = [a2(8,:)*z1+x(n)];
    x9(n) = [a2(9,:)*z1+x(n)];
    x10(n) = [a2(10,:)*z1+x(n)];
    x11(n) = [a2(11,:)*z1+x(n)];
    x12(n) = [a2(12,:)*z1+x(n)];
    x13(n) = [a2(13,:)*z1+x(n)];
    x14(n) = [a2(14,:)*z1+x(n)];
    x15(n) = [a2(15,:)*z1+x(n)];
    x16(n) = [a2(16,:)*z1+x(n)];
    
    
    y1((m(1)+n)) = x1(n); % this is the x(n-m1)
    y2((m(2)+n)) = x2(n); % this is the x(n-m2)
    y3((m(3)+n)) = x3(n);
    y4((m(4)+n)) = x4(n); 
    y5((m(5)+n)) = x5(n); % this is the x(n-m1)
    y6((m(6)+n)) = x6(n); % this is the x(n-m2)
    y7((m(7)+n)) = x7(n);
    y8((m(8)+n)) = x8(n); 
    y9((m(9)+n)) = x9(n); % this is the x(n-m1)
    y10((m(10)+n)) = x10(n); % this is the x(n-m2)
    y11((m(11)+n)) = x11(n);
    y12((m(12)+n)) = x12(n); 
    y13((m(13)+n)) = x13(n); % this is the x(n-m1)
    y14((m(14)+n)) = x14(n); % this is the x(n-m2)
    y15((m(15)+n)) = x15(n);
    y16((m(16)+n)) = x16(n); 
    
    fprintf(f_sine,'%f ',x1(n));
    fprintf(f_sine,'%f ',x2(n));
    fprintf(f_sine,'%f ',x3(n));
    fprintf(f_sine,'%f ',x4(n));
    fprintf(f_sine,'%f ',x5(n));
    fprintf(f_sine,'%f ',x6(n));
    fprintf(f_sine,'%f ',x7(n));
    fprintf(f_sine,'%f ',x8(n));
    fprintf(f_sine,'%f ',x9(n));
    fprintf(f_sine,'%f ',x10(n));
    fprintf(f_sine,'%f ',x11(n));
    fprintf(f_sine,'%f ',x12(n));
    fprintf(f_sine,'%f ',x13(n));
    fprintf(f_sine,'%f ',x14(n));
    fprintf(f_sine,'%f ',x15(n));
    fprintf(f_sine,'%f',x16(n));
    
    fprintf(f_sine,'\n');

    % treat y1(n),y2(n) ,y3(n), y4(n) as lp filter input
    %lpf1 = [lpf1,y1(n+1)+lpfConstant*lpf1(n)];
    %lpf2 = [lpf2,y2(n+1)+lpfConstant*lpf2(n)];
    %lpf3 = [lpf3,y3(n+1)+lpfConstant*lpf3(n)];
    %lpf4 = [lpf4,y4(n+1)+lpfConstant*lpf4(n)];
%     lpf1(n+1) = (kp(1)-kp(1)*bp(1))*y1(n+1)+bp(1)*lpf1(n);
%     lpf2(n+1) = (kp(2)-kp(2)*bp(2))*y2(n+1)+bp(2)*lpf2(n);
%     lpf3(n+1) = (kp(3)-kp(3)*bp(3))*y3(n+1)+bp(3)*lpf3(n);
%     lpf4(n+1) = (kp(4)-kp(4)*bp(4))*y4(n+1)+bp(4)*lpf4(n);
%     lpf5(n+1) = (kp(5)-kp(5)*bp(5))*y5(n+1)+bp(5)*lpf5(n);
%     lpf6(n+1) = (kp(6)-kp(6)*bp(6))*y6(n+1)+bp(6)*lpf6(n);
%     lpf7(n+1) = (kp(7)-kp(7)*bp(7))*y7(n+1)+bp(7)*lpf7(n);
%     lpf8(n+1) = (kp(8)-kp(8)*bp(8))*y8(n+1)+bp(8)*lpf8(n);
%     lpf9(n+1) = (kp(9)-kp(9)*bp(9))*y9(n+1)+bp(9)*lpf9(n);
%     lpf10(n+1) = (kp(10)-kp(10)*bp(10))*y10(n+1)+bp(10)*lpf10(n);
%     lpf11(n+1) = (kp(11)-kp(11)*bp(11))*y11(n+1)+bp(11)*lpf11(n);
%     lpf12(n+1) = (kp(12)-kp(12)*bp(12))*y12(n+1)+bp(12)*lpf12(n);
%     lpf13(n+1) = (kp(13)-kp(13)*bp(13))*y13(n+1)+bp(13)*lpf13(n);
%     lpf14(n+1) = (kp(14)-kp(14)*bp(14))*y14(n+1)+bp(14)*lpf14(n);
%     lpf15(n+1) = (kp(15)-kp(15)*bp(15))*y15(n+1)+bp(15)*lpf15(n);
%     lpf16(n+1) = (kp(16)-kp(16)*bp(16))*y16(n+1)+bp(16)*lpf16(n);
%     
 
    
    %lpf1(n+1) = (kp-kp*bp)*y1(n+1)+bp*lpf1(n);
    %lpf2(n+1) = (kp-kp*bp)*y2(n+1)+bp*lpf2(n);
    %lpf3(n+1) = (kp-kp*bp)*y3(n+1)+bp*lpf3(n);
    %lpf4(n+1) = (kp-kp*bp)*y4(n+1)+bp*lpf4(n);
    %lpf5(n+1) = (kp-kp*bp)*y5(n+1)+bp*lpf5(n);
    %lpf6(n+1) = (kp-kp*bp)*y6(n+1)+bp*lpf6(n);
    %lpf7(n+1) = (kp-kp*bp)*y7(n+1)+bp*lpf7(n);
    %lpf8(n+1) = (kp-kp*bp)*y8(n+1)+bp*lpf8(n);
    %lpf9(n+1) = (kp-kp*bp)*y9(n+1)+bp*lpf9(n);
    %lpf10(n+1) = (kp-kp*bp)*y10(n+1)+bp*lpf10(n);
    %%lpf11(n+1) = (kp-kp*bp)*y11(n+1)+bp*lpf11(n);
    %lpf12(n+1) = (kp-kp*bp)*y12(n+1)+bp*lpf12(n);
    %lpf13(n+1) = (kp-kp*bp)*y13(n+1)+bp*lpf13(n);
    %lpf14(n+1) = (kp-kp*bp)*y14(n+1)+bp*lpf14(n);
    %lpf15(n+1) = (kp-kp*bp)*y15(n+1)+bp*lpf15(n);
    %lpf16(n+1) = (kp-kp*bp)*y16(n+1)+bp*lpf16(n);
    
    
    
    
    
    
end
% figure(1);
% plot(y);



    
    
    
    
    
    
    

    
    








