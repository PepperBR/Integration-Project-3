#pragma once
#include <string>

class Model
{
public:
    virtual std::string getName() = 0;
    virtual int getID() = 0;
};
