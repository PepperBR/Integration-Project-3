#pragma once
#include "Meter.h"
#include "GlobalID.h"
#include "Classification.h"

class MeterCronos : public Meter
{
    public:
        std::string getNameMeter() override;
        int getIDMeter() override;
        ~MeterCronos() override;
        MeterCronos(std::string &_name, std::unique_ptr<Classification> _mode);
        const std::unique_ptr<Classification> & getMode() override;

    private:
        const int ID;
        const std::string name;
        const std::unique_ptr<Classification> mode;
};