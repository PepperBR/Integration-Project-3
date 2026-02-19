#pragma once
#include <string>

class Modelo
{
public:
    virtual std::string getName() = 0;
    virtual int getID() = 0;
};
