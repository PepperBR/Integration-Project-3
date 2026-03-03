#include "meters/Cronos/Cronos6001_A.h"
#include "core/GlobalID.h"
#include <iostream>

Cronos6001_A::Cronos6001_A()
    : Cronos(GlobalID::generateID(), "6001 A")
{
};

Cronos6001_A::~Cronos6001_A()
{
    std::cout << "Cronos 6001 A Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos6001_A::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6001_A::createMeter(int new_id) const
{
    return std::make_unique<Cronos6001_A>();
}

std::unique_ptr<Meter> Cronos6001_A::cloneMeter() const
{
    return std::make_unique<Cronos6001_A>(*this);
}