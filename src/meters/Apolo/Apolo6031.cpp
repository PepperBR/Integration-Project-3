#include "meters/Apolo/Apolo6031.h"
#include <iostream>

Apolo6031::Apolo6031()
    : Apolo("Apolo 6031")
{
};

Apolo6031::~Apolo6031()
{
    std::cout << "Apolo 6031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Apolo6031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};
