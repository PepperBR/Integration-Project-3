#include "meters/Zeus/Zeus8023.h"
#include <iostream>

Zeus8023::Zeus8023()
    : Zeus("Zeus 8023")
{
};

Zeus8023::~Zeus8023()
{
    std::cout << "Zeus 8023 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Zeus8023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

