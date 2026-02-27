#include "TwoPhaseMeter.h"

std::vector<double> & TwoPhaseMeter::getPhaseValues()
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dist(1, 220);

    return {dist(gen),dist(gen)};
};