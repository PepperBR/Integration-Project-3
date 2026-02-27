#include "meters/Cronos/Cronos6021_L.h"
#include <iostream>

Cronos6021_L::Cronos6021_L()
    : Cronos("Cronos 6021 L")
{
};

Cronos6021_L::~Cronos6021_L()
{
    std::cout << "Cronos 6021 L Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos6021_L::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

