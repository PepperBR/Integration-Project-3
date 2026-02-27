#pragma once
#include "meters/Meter.h"
//Abstract Class
class Zeus : public Meter
{
private:
    int const ID;
    std::string name;
public:
    std::string & getName() override;
    int getID() override;
    ~Zeus() override;
    Zeus(std::string _name);
};
