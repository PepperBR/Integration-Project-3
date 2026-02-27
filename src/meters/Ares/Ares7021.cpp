#include "meters/Ares/Ares7021.h"
#include <iostream>

Ares7021::Ares7021()
    : Ares("Ares 7021")
{
};

Ares7021::~Ares7021()
{
    std::cout << "Ares 7021 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

