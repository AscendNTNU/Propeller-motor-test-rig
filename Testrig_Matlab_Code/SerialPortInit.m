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
time = now;
y = zeros(1,Period/SamplingTime);

h = animatedline;
axis([1,Period,-100,100])

x = linspace(0,Period,Period/SamplingTime);

for k = 1:length(x)
    r = fscanf(s,'%i');
    while(isempty(r))
        r = fscanf(s,'%i');
    end;
    y(k) = r;
    addpoints(h,x(k),y(k));
    axis([0, (k+1)*SamplingTime, -100, 100])
    drawnow 
end