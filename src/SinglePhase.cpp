#include "SinglePhase.h"

SinglePhase::~SinglePhase()
{
    std::cout << "Single Phase Destructor is being called" << std::endl;
};

int SinglePhase::measurementPhaseA()
{
    return 220;
};
