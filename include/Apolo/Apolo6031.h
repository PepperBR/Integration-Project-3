#pragma once
#include "Apolo/Apolo.h"
#include "ThreePhaseMeter.h"
//Concret class
class Apolo6031 : public Apolo, ThreePhaseMeter
{        
    public:
        Apolo6031();
        ~Apolo6031() override;
        std::vector<double> & getPhaseValues() override;
};

