#include "meters/Cronos/Cronos7023.h"
#include <iostream>

Cronos7023::Cronos7023()
    : Cronos("Cronos 7023")
{
};

Cronos7023::~Cronos7023()
{
    std::cout << "Cronos 7023 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos7023::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

