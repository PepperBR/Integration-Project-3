#pragma once

#include "meters/Meter.h"

//Abstract Class
class Zeus : public Meter
{
public:
    using Meter::Meter;

    ~Zeus() override;
    Zeus(int id, std::string model);
};
