#pragma once
#include "Meter.h"
#include "GlobalID.h"

class MeterCronos : public Meter
{
    public:
        std::string getNameMeter() override;
        int getIDMeter() override;
        ~MeterCronos() override;
        MeterCronos();
        
    private:
        const int ID;
        const std::string name;
};