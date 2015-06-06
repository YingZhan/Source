
% lpf1 = zeros(N,1);
% lpf2 = zeros(N,1);
% lpf3 = zeros(N,1);
% lpf4 = zeros(N,1);
% lpf5 = zeros(N,1);
% lpf6 = zeros(N,1);
% lpf7 = zeros(N,1);
% lpf8 = zeros(N,1);
% lpf9 = zeros(N,1);
% lpf10 = zeros(N,1);
% lpf11 = zeros(N,1);
% lpf12 = zeros(N,1);
% lpf13 = zeros(N,1);
% lpf14 = zeros(N,1);
% lpf15 = zeros(N,1);
% lpf16 = zeros(N,1);

m = [919, 997, 1061, 1093, 1129, 1151, 1171, 1187, 1213, 1237, 1259, 1283, 1303, 1319, 1327, 1361];
fs = 44100;
for i = 1:16
    kp(i) = 10^(-1*m(i)/fs);  
    q = 1.25/3;
    bp(i) = 20* log10(kp(i))*log(10)/80*(1-1/(q*q));
    %bp(i) = 1/bp(i);
end
lpf1(1) = (kp(1)-kp(1)*bp(1))*x(1);
lpf2(1) = (kp(2)-kp(2)*bp(2))*x(1);
lpf3(1) = (kp(3)-kp(3)*bp(3))*x(1);
lpf4(1) = (kp(4)-kp(4)*bp(4))*x(1);
lpf5(1) = (kp(5)-kp(5)*bp(5))*x(1);
lpf6(1) = (kp(6)-kp(6)*bp(6))*x(1);
lpf7(1) = (kp(7)-kp(7)*bp(7))*x(1);
lpf8(1) = (kp(8)-kp(8)*bp(8))*x(1);
lpf9(1) = (kp(9)-kp(9)*bp(9))*x(1);
lpf10(1) = (kp(10)-kp(10)*bp(10))*x(1);
lpf11(1) = (kp(11)-kp(11)*bp(11))*x(1);
lpf12(1) = (kp(12)-kp(12)*bp(12))*x(1);
lpf13(1) = (kp(13)-kp(13)*bp(13))*x(1);
lpf14(1) = (kp(14)-kp(14)*bp(14))*x(1);
lpf15(1) = (kp(15)-kp(15)*bp(15))*x(1);
lpf16(1) = (kp(16)-kp(16)*bp(16))*x(1);

for n = 2:N

lpf1(n) = (kp(1)-kp(1)*bp(1))*x(n)+bp(1)*lpf1(n-1);
lpf2(n) = (kp(2)-kp(2)*bp(2))*x(n)+bp(2)*lpf2(n-1);
lpf3(n) = (kp(3)-kp(3)*bp(3))*x(n)+bp(3)*lpf3(n-1);
lpf4(n) = (kp(4)-kp(4)*bp(4))*x(n)+bp(4)*lpf4(n-1);
lpf5(n) = (kp(5)-kp(5)*bp(5))*x(n)+bp(5)*lpf5(n-1);
lpf6(n) = (kp(6)-kp(6)*bp(6))*x(n)+bp(6)*lpf6(n-1);
lpf7(n) = (kp(7)-kp(7)*bp(7))*x(n)+bp(7)*lpf7(n-1);
lpf8(n) = (kp(8)-kp(8)*bp(8))*x(n)+bp(8)*lpf8(n-1);
lpf9(n) = (kp(9)-kp(9)*bp(9))*x(n)+bp(9)*lpf9(n-1);
lpf10(n) = (kp(10)-kp(10)*bp(10))*x(n)+bp(10)*lpf10(n-1);
lpf11(n) = (kp(11)-kp(11)*bp(11))*x(n)+bp(11)*lpf11(n-1);
lpf12(n) = (kp(12)-kp(12)*bp(12))*x(n)+bp(12)*lpf12(n-1);
lpf13(n) = (kp(13)-kp(13)*bp(13))*x(n)+bp(13)*lpf13(n-1);
lpf14(n) = (kp(14)-kp(14)*bp(14))*x(n)+bp(14)*lpf14(n-1);
lpf15(n) = (kp(15)-kp(15)*bp(15))*x(n)+bp(15)*lpf15(n-1);
lpf16(n) = (kp(16)-kp(16)*bp(16))*x(n)+bp(16)*lpf16(n-1);
    
end
