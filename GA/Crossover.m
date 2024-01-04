function [o1,o2] = Crossover(p1,p2)
    cut = round(2*rand(1)+1)
 
    o1 = [p1(1:cut), p2(cut+1:end)]
    o2 = [p2(1:cut), p1(cut+1:end)]

end

