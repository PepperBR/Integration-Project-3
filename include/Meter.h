#pragma once
#include <string>
#include <iostream>
#include "Classification.h"

class Meter
{
    public:
        virtual std::string getNameMeter() = 0;
        virtual int getIDMeter() = 0;
        virtual const std::unique_ptr<Classification> & getMode() = 0;
        virtual ~Meter()
        {
            std::cout << "Virtual Meter Destructor is begin called" << std::endl;
        };
};