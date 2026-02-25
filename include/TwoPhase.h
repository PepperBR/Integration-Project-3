#pragma once
#include "Classification.h"

class TwoPhase : public Classification
{
public:
    int measurementPhaseA() override;
    int measurementPhaseB() override;
    ~TwoPhase() override;
};
