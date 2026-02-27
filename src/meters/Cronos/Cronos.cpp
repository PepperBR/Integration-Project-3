#include "meters/Cronos/Cronos.h"

Cronos::Cronos(std::string _name)
    : ID(GlobalID::generateID()),
      name(_name)
{
};

Cronos::~Cronos()
{
    std::cout << "Cronos Meter Destructor is begin called" << std::endl;
};

std::string & Cronos::getName()
{
    return name;
};

int Cronos::getID() 
{
    return ID;
};
