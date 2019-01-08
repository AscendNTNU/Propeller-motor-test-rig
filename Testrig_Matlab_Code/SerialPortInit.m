clear all;
delete(instrfindall);
%%Variables (Edit ourself)
SerialPort='com12'; %serial port
MaxDeviation = 30;%Maximum Allowable Change from one value to next 
SamplingTime=0.1;%time interval between each input.
Period = 10;

%%Set up the serial port object
s = serial(SerialPort)
set(s,'BaudRate',9600);
fopen(s);

figure();
h = animatedline;
h2 = animatedline;
axis([1,Period,-100,100])
x = linspace(0,Period,Period/SamplingTime);
pause(1);
for k = 1:length(x)
    re = SerialLogToFile(s, 'test');
    addpoints(h,x(k),re(1));
    addpoints(h2,x(k), re(2));
    axis([0, (k+1)*SamplingTime, -10, 10])
    drawnow 
end

fclose(s)
delete(s)
clear s