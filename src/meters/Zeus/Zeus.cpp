#include "meters/Zeus/Zeus.h"

Zeus::Zeus(int id, std::string model)
    : Meter(id, "Zeus" , model)
{
};

Zeus::~Zeus()
{
    std::cout << "Zeus Meter Destructor is begin called" << std::endl;
};