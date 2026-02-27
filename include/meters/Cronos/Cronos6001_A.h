#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos6001_A : public Cronos, ThreePhaseMeter
{        
    public:
        Cronos6001_A();
        ~Cronos6001_A() override;
        std::vector<double> & getPhaseValues() override;
};

