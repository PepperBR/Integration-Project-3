#pragma once
#include <string>
#include "GlobalID.h"

// Todos os medidores terão comportamentos parecidos

class Meter
{
    public:
        virtual ~Meter();
        virtual const int & getID() = 0;
        virtual const std::string & getName() = 0;
};
