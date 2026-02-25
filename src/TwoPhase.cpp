#include "TwoPhase.h"

TwoPhase::~TwoPhase()
{
    std::cout << "Two Phase Destructor is being called" << std::endl;
};

int TwoPhase::measurementPhaseA()
{
    return 220;
};

int TwoPhase::measurementPhaseB()
{
    return 220;
};