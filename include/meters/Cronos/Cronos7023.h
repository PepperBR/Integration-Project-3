#pragma once
#include "meters/Cronos/Cronos.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Cronos7023 : public Cronos, ThreePhaseMeter
{        
    public:
        Cronos7023();
        ~Cronos7023() override;
        std::vector<double> & getPhaseValues() override;
};

