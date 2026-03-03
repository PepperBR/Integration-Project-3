#include "meters/Apolo/Apolo.h"


Apolo::Apolo(int id, std::string model)
    : Meter(id, "Apolo" , model)
{
};

Apolo::~Apolo()
{
    std::cout << "Apolo Meter Destructor is begin called" << std::endl;
};
