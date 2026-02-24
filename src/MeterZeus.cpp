#include "MeterZeus.h"

MeterZeus::MeterZeus(std::string &_name)
    : ID(GlobalID::generateID()),
      name(_name)
{
    std::cout << "ID = " << ID << std::endl;
};

MeterZeus::~MeterZeus()
{
    std::cout << "Meter Zeus Destructor " << ID << " begin called" << std::endl;
}
int MeterZeus::getIDMeter()
{
    return ID;
};

std::string MeterZeus::getNameMeter()
{
    return name;
};

