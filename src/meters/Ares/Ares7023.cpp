#include "meters/Ares/Ares7023.h"
#include <iostream>

Ares7023::Ares7023()
    : Ares("Ares 7023")
{
};

Ares7023::~Ares7023()
{
    std::cout << "Ares 7023 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Ares7023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

