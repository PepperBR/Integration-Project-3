#pragma once
#include <string>
#include <iostream>

class Meter{
    public:
        virtual std::string getNameMeter() = 0;
        virtual int getIDMeter() = 0;
        virtual ~Meter(){
            std::cout << "Virtual Meter Destructor is begin called" << std::endl;
        };
};