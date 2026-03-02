#pragma once
#include "meters/Meter.h"
#include "core/GlobalID.h" 
//Abstract Class
class Apolo : public Meter
{
public:
    std::string & getName() override;
    int getID() override;
    ~Apolo() override;
    Apolo(std::string _name);
};

