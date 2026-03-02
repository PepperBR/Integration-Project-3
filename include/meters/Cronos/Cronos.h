#pragma once
#include "meters/Meter.h"
#include "core/GlobalID.h"
//Abstract Class
class Cronos : public Meter
{
public:
    std::string & getName() override;
    int getID() override;
    ~Cronos() override;
    Cronos(std::string _name);
};
