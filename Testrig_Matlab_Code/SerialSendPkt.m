function [] = SerialSendPkt(s, id, data)
%SERIALSENDPKT Sends bytes of data to serial
%   Tansmition starts with ASCII 't' followed by the length of data, and
%   then the data
    fprintf(s,'%c','t');
    fwrite(s, id);
    fwrite(s, length(data));
    for d = data
        fwrite(s,d)
    end
end

