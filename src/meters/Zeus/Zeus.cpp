#include "meters/Zeus/Zeus.h"

Zeus::Zeus(std::string _name)
    : ID(GlobalID::generateID()),
      name(_name)
{
};

Zeus::~Zeus()
{
    std::cout << "Zeus Meter Destructor is begin called" << std::endl;
};

std::string & Zeus::getName()
{
    return name;
};

int Zeus::getID() 
{
    return ID;
};
