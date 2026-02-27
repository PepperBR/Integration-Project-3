#pragma once
#include "meters/Apolo/Apolo.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Apolo6031 : public Apolo, ThreePhaseMeter
{        
    public:
        Apolo6031();
        ~Apolo6031() override;
        std::vector<double> & getPhaseValues() override;
};

