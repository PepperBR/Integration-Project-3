#include "meters/Cronos/Cronos.h"

Cronos::Cronos(int id, std::string model)
    : Meter(id, "Cronos", model)
{
};

Cronos::~Cronos()
{
    std::cout << "Cronos Meter Destructor is begin called" << std::endl;
};

