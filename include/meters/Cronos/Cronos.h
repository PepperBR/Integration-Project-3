#pragma once

#include "meters/Meter.h"

//Abstract Class
class Cronos : public Meter
{
public:
    ~Cronos() override;
    Cronos(int id, std::string model);
};
