#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos6021_L : public Cronos, ThreePhaseMeter
{        
    public:
        Cronos6021_L();
        ~Cronos6021_L() override;
        std::vector<double> & getPhaseValues() override;
};

