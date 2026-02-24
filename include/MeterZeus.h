#pragma once
#include "Meter.h"
#include "GlobalID.h"

class MeterZeus  : public Meter
{
    public:
        std::string getNameMeter() override;
        int getIDMeter() override;
        ~MeterZeus() override;
        MeterZeus(std::string &_name);
        
    private:
        const int ID;
        const std::string name;
};