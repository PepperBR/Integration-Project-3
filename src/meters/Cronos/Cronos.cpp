#include "meters/Cronos/Cronos.h"
#include <iostream>

Cronos::Cronos(int id, std::string model)
    : Meter(id, "Cronos", model)
{
};

Cronos::Cronos(const Cronos& other, int new_id) 
    : Meter(other, new_id) 
{
};


Cronos::~Cronos()
{
    std::cout << "Cronos Meter Destructor is begin called" << std::endl;
};

