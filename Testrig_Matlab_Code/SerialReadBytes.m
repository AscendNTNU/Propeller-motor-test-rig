function [ data ] = SerialReadBytes(s, length) 
%SERIALREADBYTES Summary of this function goes here
%   Detailed explanation goes here
    data = zeros(1, length);
    for k = 1:length
        c = 0;
        r = fscanf(s,'%i');
        while(isempty(r))
            c = c+1;
            if(c > 4)
                disp('Could not read data');
                r = 0;
                break;
            end
            r = fscanf(s,'%i');
        end
        data(k) = r;
    end
end

