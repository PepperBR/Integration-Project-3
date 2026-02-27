#include "meters/Zeus/Zeus8031.h"
#include <iostream>

Zeus8031::Zeus8031()
    : Zeus("Zeus 8031")
{
};

Zeus8031::~Zeus8031()
{
    std::cout << "Zeus 8031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Zeus8031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};
