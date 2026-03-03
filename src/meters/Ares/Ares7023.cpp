#include "meters/Ares/Ares7023.h"
#include "core/GlobalID.h"
#include <iostream>

Ares7023::Ares7023()
    : Ares(GlobalID::generateID(), "7023")
{
};

Ares7023::~Ares7023()
{
    std::cout << "Ares 7023 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7023::createMeter(int new_id) const
{
    return std::make_unique<Ares7023>();
}

std::unique_ptr<Meter> Ares7023::cloneMeter() const
{
    return std::make_unique<Ares7023>(*this);
}


