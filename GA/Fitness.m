function [fitness] = Fitness(ScopeData)

    size(ScopeData,1);
    for i = 1:size(ScopeData,1);
        if ScopeData(i,2) < 1
            ScopeData(i,2)
            ScopeData(i,1)
            break
        end
    end

end