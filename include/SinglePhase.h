#pragma once
#include "Classification.h"

class SinglePhase : public Classification
{
public:
    int measurementPhaseA() override;
    ~SinglePhase() override;
};
