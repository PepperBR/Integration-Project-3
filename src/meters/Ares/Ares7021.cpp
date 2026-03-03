#include "meters/Ares/Ares7021.h"
#include "core/GlobalID.h"
#include <iostream>

Ares7021::Ares7021()
    : Ares(GlobalID::generateID(), "7021")
{
};

Ares7021::~Ares7021()
{
    std::cout << "Ares 7021 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7021::createMeter(int new_id) const
{
    return std::make_unique<Ares7021>();
}

std::unique_ptr<Meter> Ares7021::cloneMeter() const
{
    return std::make_unique<Ares7021>(*this);
}

