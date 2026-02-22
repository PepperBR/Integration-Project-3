#include "MeterAres.h"

MeterAres::MeterAres()
    : ID(GlobalID::generateID())
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

