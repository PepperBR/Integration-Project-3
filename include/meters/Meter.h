#pragma once

#include <string>
#include <iostream>
#include <vector>

//Abstract Class
class Meter
{
protected:
    int const ID;
    std::string name;
public:
    Meter(int id, std::string name) 
            : ID(id), name(std::move(name)) {};
    virtual std::vector<double> & getPhaseValues() = 0;
    virtual std::string & getName() = 0;
    virtual int getID() = 0;
    virtual ~Meter()
    {
        std::cout << "Virtual Meter Destructor is begin called" << std::endl;
    };
};
