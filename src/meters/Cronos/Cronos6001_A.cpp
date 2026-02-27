#include "meters/Cronos/Cronos6001_A.h"
#include <iostream>

Cronos6001_A::Cronos6001_A()
    : Cronos("Cronos 6001 A")
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

