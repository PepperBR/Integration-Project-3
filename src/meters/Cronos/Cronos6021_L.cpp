#include "meters/Cronos/Cronos6021_L.h"
#include "core/GlobalID.h"
#include <iostream>

Cronos6021_L::Cronos6021_L()
    : Cronos(GlobalID::generateID(), "6021 L")
{
};

Cronos6021_L::~Cronos6021_L()
{
    std::cout << "Cronos 6021 L Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos6021_L::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6021_L::createMeter(int new_id) const
{
    return std::make_unique<Cronos6021_L>();
}

std::unique_ptr<Meter> Cronos6021_L::cloneMeter() const
{
    return std::make_unique<Cronos6021_L>(*this);
}