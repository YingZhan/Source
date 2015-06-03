BufferSize = 512;
Freq = 100;
fs = 44100/4;
DCInput = ones(1,BufferSize);
SinInput = zeros(1,BufferSize);
for i = 1:BufferSize
    SinInput(i) = sin(2*pi*Freq/fs);
end

DCOutput = ones(1,BufferSize);
SinOutput = zeros(1,BufferSize);


