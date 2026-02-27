#pragma once
#include "meters/Zeus/Zeus.h"
#include "meters/Phase/ThreePhaseMeter.h"
//Concret class
class Zeus8031 : public Zeus, ThreePhaseMeter
{        
    public:
        Zeus8031();
        ~Zeus8031() override;
        std::vector<double> & getPhaseValues() override;
};

