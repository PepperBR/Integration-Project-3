#pragma once
#include "meters/Zeus/Zeus.h"
#include "meters/Phase/SinglePhaseMeter.h"
//Concret class
class Zeus8021 : public Zeus, SinglePhaseMeter
{        
public:
    std::vector<double> & getPhaseValues() override;

    std::unique_ptr<Meter> createMeter(int new_id) const override;
    std::unique_ptr<Meter> cloneMeter() const override;

    Zeus8021();
    ~Zeus8021() override;

    Zeus8021(const Zeus8021& other) = default;
};

