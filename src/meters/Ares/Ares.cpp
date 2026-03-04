#include "meters/Ares/Ares.h"
#include <iostream>

Ares::Ares(int id, std::string model)
    : Meter(id, "Ares", model)
{
};

Ares::Ares(const Ares& other, int new_id) 
    : Meter(other, new_id) 
{
};

Ares::~Ares()
{
    std::cout << "Ares Meter Destructor is begin called" << std::endl;
};
