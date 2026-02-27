#include "meters/Cronos/Cronos7023_L.h"
#include <iostream>

Cronos7023_L::Cronos7023_L()
    : Cronos("Cronos 7023 L")
{
};

Cronos7023_L::~Cronos7023_L()
{
    std::cout << "Cronos 7023 L Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos7023_L::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

