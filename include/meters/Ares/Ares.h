#pragma once
#include "meters/Meter.h"
#include "core/GlobalID.h"
//Abstract Class
class Ares : public Meter
{
public:
    std::string & getName() override;
    int getID() override;
    ~Ares() override;
    Ares(std::string _name);
};
