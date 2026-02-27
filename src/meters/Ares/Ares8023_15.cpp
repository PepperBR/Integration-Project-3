#include "meters/Ares/Ares8023_15.h"
#include <iostream>

Ares8023_15::Ares8023_15()
    : Ares("Ares 8023 15")
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
