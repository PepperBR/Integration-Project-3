#pragma once
#include "Meter.h"
#include "GlobalID.h"

class MeterApolo : public Meter
{
    public:
        std::string getNameMeter() override;
        int getIDMeter() override;
        ~MeterApolo() override;
        MeterApolo();
        
    private:
        const int ID;
        const std::string name;
};