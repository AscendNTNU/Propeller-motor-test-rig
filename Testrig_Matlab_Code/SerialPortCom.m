clear all; close all;
delete(instrfindall);

SerialPort='com12'; %serial port

s = serial(SerialPort);
set(s,'BaudRate',9600);
fopen(s);
while(1)
    i = input('Velg mulighet: q: quit, t: test, l: log data: ', 's');
    if(i == 'q')
        break;
    elseif(i == 't')
        SerialSendPkt(s, 1, [25, 43, 73, 12]);
        SerialReadBytes(s, 4)
    elseif(i == 'l')
        Period = input('Select time interval [s]: ');
        SamplingTime=0.1;%time interval between each input.
        figure();
        h = animatedline;
        h2 = animatedline;
        axis([0,Period,-10,10])
        x = linspace(0,Period,Period/SamplingTime);
        pause(1);
        for k = 1:length(x)
            re = SerialLogToFile(s, 'test');
            addpoints(h,x(k),re(1));
            addpoints(h2,x(k), re(2));
            drawnow 
        end
    else
        disp('Ugyldig input.')
    end
end

fclose(s);
delete(s);
clear s
    