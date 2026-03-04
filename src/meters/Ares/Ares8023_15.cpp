#include "meters/Ares/Ares8023_15.h"
#include "core/GlobalID.h"
#include <iostream>

Ares8023_15::Ares8023_15()
    : Ares(GlobalID::generateID(), "8023 15")
{
};

Ares8023_15::Ares8023_15(const Ares8023_15& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares8023_15::~Ares8023_15()
{
    std::cout << "Ares 8023 15 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares8023_15::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares8023_15::cloneMeter() const
{
    return std::make_unique<Ares8023_15>(*this, GlobalID::generateID());
}



