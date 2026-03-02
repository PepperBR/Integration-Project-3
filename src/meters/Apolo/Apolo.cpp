#include "meters/Apolo/Apolo.h"

Apolo::Apolo(std::string _name)
    : Meter(GlobalID::generateID(), _name)
{
};

Apolo::~Apolo()
{
    std::cout << "Apolo Meter Destructor is begin called" << std::endl;
};

std::string & Apolo::getName()
{
    return name;
};

int Apolo::getID() 
{
    return ID;
};

