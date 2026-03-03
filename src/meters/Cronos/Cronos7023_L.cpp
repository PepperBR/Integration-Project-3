#include "meters/Cronos/Cronos7023_L.h"
#include "core/GlobalID.h"
#include <iostream>

Cronos7023_L::Cronos7023_L()
    : Cronos(GlobalID::generateID(), "7023 L")
{
};

Cronos7023_L::~Cronos7023_L()
{
    std::cout << "Cronos 7023 L Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos7023_L::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos7023_L::createMeter(int new_id) const
{
    return std::make_unique<Cronos7023_L>();
}

std::unique_ptr<Meter> Cronos7023_L::cloneMeter() const
{
    return std::make_unique<Cronos7023_L>(*this);
}