clear all; close all;
delete(instrfindall);

SerialPort='com12'; %serial port

s = serial(SerialPort)
set(s,'BaudRate',9600);
fopen(s);
while(1)
    i = input('Velg mulighet: q: quit, t: test: ', 's');
    if(i == 'q')
        break;
    elseif(i == 't')
        SerialSendPkt(s, 1, [25, 43, 73, 12]);
        SerialReadBytes(s, 4)
    else
        disp('Ugyldig input.')
    end
end

fclose(s);
delete(s);
clear s
    