#include "meters/Ares/Ares7031.h"
#include "core/GlobalID.h"
#include <iostream>

Ares7031::Ares7031()
    : Ares(GlobalID::generateID(), "7031")
{
};

Ares7031::~Ares7031()
{
    std::cout << "Ares 7031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7031::createMeter(int new_id) const
{
    return std::make_unique<Ares7031>();
}

std::unique_ptr<Meter> Ares7031::cloneMeter() const
{
    return std::make_unique<Ares7031>(*this);
}


