#include "meters/Apolo/Apolo6031.h"
#include "core/GlobalID.h"
#include <iostream>

Apolo6031::Apolo6031()
    : Apolo(GlobalID::generateID(), "6031")
{
};

Apolo6031::~Apolo6031()
{
    std::cout << "Apolo 6031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Apolo6031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Apolo6031::createMeter(int new_id) const
{
    return std::make_unique<Apolo6031>();
}

std::unique_ptr<Meter> Apolo6031::cloneMeter() const
{
    return std::make_unique<Apolo6031>(*this);
}

