#include "meters/Cronos/Cronos6021_A.h"
#include <iostream>

Cronos6021_A::Cronos6021_A()
    : Cronos("Cronos 6021 A")
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

