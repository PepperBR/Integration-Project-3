#include "meters/Ares/Ares.h"

Ares::Ares(std::string _name)
    : ID(GlobalID::generateID()),
      name(_name)
{
};

Ares::~Ares()
{
    std::cout << "Ares Meter Destructor is begin called" << std::endl;
};

std::string & Ares::getName()
{
    return name;
};

int Ares::getID() 
{
    return ID;
};
