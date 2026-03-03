#pragma once

#include "meters/Meter.h"

//Abstract Class
class Ares : public Meter
{
public:
    ~Ares() override;
    Ares(int id, std::string model);
};
