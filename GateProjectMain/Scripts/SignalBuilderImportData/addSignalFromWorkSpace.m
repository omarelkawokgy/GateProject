%CONSTANTS
SAMPLE_TIME = 0.001; 
NUMBER_CYCLES = 2;
TOTAL_TIME = 60;
HIGH = 1010;
LOW = 23;

TIME = transpose(0:0.001:TOTAL_TIME);

%Cycle1
start1 = 3.88;
finish1 = 19;
%Cycle2
start2 = 23;
finish2 = 38;
%Cycle3
start3 = 43;
finish3 = 58;
%Cycle4
start4 = 79;
finish4 = 94;

start = [start1, start2, start3, start4];
start = start.*(1/SAMPLE_TIME);
finish = [finish1, finish2, finish3, finish4];
finish = finish.*(1/SAMPLE_TIME);


Signal = HIGH*ones(start(1),1);
for c=1:NUMBER_CYCLES

    counter = 0;
    tempSignal = ones((finish(c) - start(c)),1);
    tempValue = LOW;
    
    for i=1:(finish(c) - start(c))

       if counter > 30
           %toggle value
           if tempValue == HIGH
               tempValue = LOW;
           else
               tempValue = HIGH;
           end
           counter = 0;
       else
           counter = counter + 1;
       end
       tempSignal(i) = tempValue;
    end

    Signal = cat(1, Signal, tempSignal);
    
    if c < NUMBER_CYCLES
        Signal = cat(1, Signal, LOW*ones((start(c+1) - finish(c)),1));
    end
end
Signal = cat(1, Signal, HIGH*ones((TOTAL_TIME * (1/SAMPLE_TIME)) + 1 ...
    - (finish(NUMBER_CYCLES)),1));


signalbuilder('gate_V22_2016a/HardwareInputWrapper/MIL/Signal Builder', 'appendsignal',TIME, Signal, 'Signal5');