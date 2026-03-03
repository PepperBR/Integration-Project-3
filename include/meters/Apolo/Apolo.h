#pragma once

#include "meters/Meter.h"

//Abstract Class
class Apolo : public Meter
{
public:
    ~Apolo() override;
    Apolo(int id, std::string model);
};

