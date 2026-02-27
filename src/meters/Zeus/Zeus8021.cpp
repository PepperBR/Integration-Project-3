#include "meters/Zeus/Zeus8021.h"
#include <iostream>

Zeus8021::Zeus8021()
    : Zeus("Zeus 8021")
{
};

Zeus8021::~Zeus8021()
{
    std::cout << "Zeus 8021 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Zeus8021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};
