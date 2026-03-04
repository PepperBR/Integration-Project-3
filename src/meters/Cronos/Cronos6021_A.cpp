#include "meters/Cronos/Cronos6021_A.h"
#include "core/GlobalID.h"
#include <iostream>

Cronos6021_A::Cronos6021_A()
    : Cronos(GlobalID::generateID(), "6021 A")
{
};

Cronos6021_A::Cronos6021_A(const Cronos6021_A& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos6021_A::~Cronos6021_A()
{
    std::cout << "Cronos 6021 A Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos6021_A::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6021_A::cloneMeter() const
{
    return std::make_unique<Cronos6021_A>(*this, GlobalID::generateID());
}
