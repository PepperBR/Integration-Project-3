#include "ThreePhase.h"

ThreePhase::~ThreePhase()
{
    std::cout << "Three Phase Destructor is being called" << std::endl;
};

int ThreePhase::measurementPhaseA()
{
    return 220;
};

int ThreePhase::measurementPhaseB()
{
    return 220;
};


int ThreePhase::measurementPhaseC()
{
    return 220;
};