#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "core/GlobalID.h"
//Interface
class Meter
{
    public:
        virtual std::vector<double> & getPhaseValues() = 0;
        virtual std::string & getName() = 0;
        virtual int getID() = 0;
        virtual ~Meter()
        {
            std::cout << "Virtual Meter Destructor is begin called" << std::endl;
        };
};
