#pragma once
#include "Classification.h"

class ThreePhase : public Classification
{
public:
    int measurementPhaseA() override;
    int measurementPhaseB() override;
    int measurementPhaseC() override;
    ~ThreePhase() override;
};
