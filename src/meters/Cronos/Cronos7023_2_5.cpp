#include "meters/Cronos/Cronos7023_2_5.h"
#include "core/GlobalID.h"
#include <iostream>

Cronos7023_2_5::Cronos7023_2_5()
    : Cronos(GlobalID::generateID(), "7023 2.5")
{
};

Cronos7023_2_5::~Cronos7023_2_5()
{
    std::cout << "Cronos 7023 2.5 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos7023_2_5::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Cronos7023_2_5::createMeter(int new_id) const
{
    return std::make_unique<Cronos7023_2_5>();
}

std::unique_ptr<Meter> Cronos7023_2_5::cloneMeter() const
{
    return std::make_unique<Cronos7023_2_5>(*this);
}