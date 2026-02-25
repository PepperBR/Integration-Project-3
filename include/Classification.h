#pragma once
#include <iostream>

class Classification
{
    public:
        virtual int measurementPhaseA() { return 0;};
        virtual int measurementPhaseB() { return 0;};
        virtual int measurementPhaseC() { return 0;};
        virtual ~Classification()
        {
            std::cout << "Virtual Classification Destructor is begin called" << std::endl;
        };
};