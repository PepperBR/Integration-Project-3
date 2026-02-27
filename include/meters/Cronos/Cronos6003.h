#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Cronos6003 : public Cronos, TwoPhaseMeter
{        
    public:
        Cronos6003();
        ~Cronos6003() override;
        std::vector<double> & getPhaseValues() override;
};

