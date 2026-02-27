#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Cronos7023_L : public Cronos, SinglePhaseMeter
{        
    public:
        Cronos7023_L();
        ~Cronos7023_L() override;
        std::vector<double> & getPhaseValues() override;
};

