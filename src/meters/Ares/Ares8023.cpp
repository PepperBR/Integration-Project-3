#include "meters/Ares/Ares8023.h"
#include <iostream>

Ares8023::Ares8023()
    : Ares("Ares 8023")
{
};

Ares8023::~Ares8023()
{
    std::cout << "Ares 8023 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares8023::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};
