#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Cronos6021_A : public Cronos, SinglePhaseMeter
{        
    public:
        Cronos6021_A();
        ~Cronos6021_A() override;
        std::vector<double> & getPhaseValues() override;
};

