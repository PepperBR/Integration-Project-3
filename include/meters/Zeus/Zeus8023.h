#pragma once
#include "meters/Zeus/Zeus.h"
#include "meters/Phase/TwoPhaseMeter.h"
//Concret class
class Zeus8023 : public Zeus, TwoPhaseMeter
{        
    public:
        Zeus8023();
        ~Zeus8023() override;
        std::vector<double> & getPhaseValues() override;
};

