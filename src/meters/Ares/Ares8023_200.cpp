#include "meters/Ares/Ares8023_200.h"
#include <iostream>

Ares8023_200::Ares8023_200()
    : Ares("Ares 8023 200")
{
};

Ares8023_200::~Ares8023_200()
{
    std::cout << "Ares 8023 200 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares8023_200::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};
