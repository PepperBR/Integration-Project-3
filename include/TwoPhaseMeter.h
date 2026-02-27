#pragma once
#include <vector>
#include <random>

class TwoPhaseMeter
{
    public:
        ~TwoPhaseMeter();
        std::vector<double> & getPhaseValues();
};

