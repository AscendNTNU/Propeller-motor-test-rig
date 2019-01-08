function [scan] = SerialLogToFile(s,  filename )
%SERIALREADTOFILE Summary of this function goes here
%   Detailed explanation goes here
    scan = fscanf(s,'%f');
    while(isempty(scan))
        scan = fscanf(s,'%f');
    end;
    filename = strcat(filename, '.mat');
    if exist(filename, 'file') == 2
        load(filename);
        r(:, length(r)+1) = scan;
        save(filename,'-append','r')
    else
        r = scan;
        save(filename,'r');
    end
end

