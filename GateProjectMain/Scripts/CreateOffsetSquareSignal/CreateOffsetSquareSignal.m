signalName = 'simout';
OFFSET = 0.5;
SAMPLE_TIME = 0.001;
Y_OFFSET = OFFSET;
X_OFFSET = (1/SAMPLE_TIME) * ;

max = simout.Data + Y_OFFSET;
min = simout.Data - Y_OFFSET;

for i=1:length(simout.Data)
    if (i - X_OFFSET) > 0
        if (simout.Data(i - X_OFFSET) < (simout.Data(i))) 
            for j=(i - X_OFFSET):(i)
                % pos Edge
                max(j) = simout.Data(i) + Y_OFFSET;                
                minCounter = i;
                min(minCounter) = simout.Data(i - X_OFFSET) - Y_OFFSET;
                minCounter = minCounter + 1;
            end
        end
        if (simout.Data(i - X_OFFSET) > (simout.Data(i)))
            for j=(i - X_OFFSET):i
                % neg Edge
                minCounter = i;
                min(j) = simout.Data(i) - Y_OFFSET;
                minCounter = minCounter - 1;
                max(j) = simout.Data(i - X_OFFSET) + Y_OFFSET;
            end
        end
    end
end

signalbuilder('untitled/Signal Builder', 'set', 2, 1, simout.Time, max);
signalbuilder('untitled/Signal Builder', 'set', 3, 1, simout.Time, min);