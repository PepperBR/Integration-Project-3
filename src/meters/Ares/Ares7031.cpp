#include "meters/Ares/Ares7031.h"
#include <iostream>

Ares7031::Ares7031()
    : Ares("Ares 7031")
{
};

Ares7031::~Ares7031()
{
    std::cout << "Ares 7031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

