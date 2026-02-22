#pragma once
#include "Meter.h"
#include "GlobalID.h"

class MeterAres : public Meter
{
    public:
        std::string getNameMeter() override;
        int getIDMeter() override;
        ~MeterAres() override;
        MeterAres();
        
    private:
        const int ID;
        const std::string name;
};