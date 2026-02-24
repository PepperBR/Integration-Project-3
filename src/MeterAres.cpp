#include "MeterAres.h"

MeterAres::MeterAres(std::string &_name)
    : ID(GlobalID::generateID()),
      name(_name)
{
    std::cout << "ID = " << ID << std::endl;
};

MeterAres::~MeterAres()
{
    std::cout << "Meter Ares Destructor " << ID << " begin called" << std::endl;
}
int MeterAres::getIDMeter()
{
    return ID;
};

std::string MeterAres::getNameMeter()
{
    return name;
};

