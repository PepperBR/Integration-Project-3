#include "meters/Cronos/Cronos6003.h"
#include <iostream>

Cronos6003::Cronos6003()
    : Cronos("Cronos 6003")
{
};

Cronos6003::~Cronos6003()
{
    std::cout << "Cronos 6003 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Cronos6003::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

