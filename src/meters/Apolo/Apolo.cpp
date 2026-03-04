#include "meters/Apolo/Apolo.h"
#include <iostream>

Apolo::Apolo(int id, std::string model)
    : Meter(id, "Apolo" , model)
{
};

Apolo::Apolo(const Apolo& other, int new_id) 
    : Meter(other, new_id) 
{
};

Apolo::~Apolo()
{
    std::cout << "Apolo Meter Destructor is begin called" << std::endl;
};
