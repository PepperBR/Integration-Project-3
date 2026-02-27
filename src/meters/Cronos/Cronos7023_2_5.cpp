#include "meters/Cronos/Cronos7023_2_5.h"
#include <iostream>

Cronos7023_2_5::Cronos7023_2_5()
    : Cronos("Cronos 7023 2.5")
{
};

Cronos7023_2_5::~Cronos7023_2_5()
{
    std::cout << "Cronos 7023 2.5 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos7023_2_5::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

