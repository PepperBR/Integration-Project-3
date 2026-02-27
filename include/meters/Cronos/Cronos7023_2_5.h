#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Cronos7023_2_5 : public Cronos, TwoPhaseMeter
{        
    public:
        Cronos7023_2_5();
        ~Cronos7023_2_5() override;
        std::vector<double> & getPhaseValues() override;
};

