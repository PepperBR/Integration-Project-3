#pragma once
#include "meters/Meter.h"
#include "core/GlobalID.h"
//Abstract Class
class Zeus : public Meter
{
public:
    std::string & getName() override;
    int getID() override;
    ~Zeus() override;
    Zeus(std::string _name);
};
