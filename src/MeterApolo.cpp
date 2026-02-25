#include "MeterApolo.h"

MeterApolo::MeterApolo(std::string &_name)
    : ID(GlobalID::generateID()),
      name(_name)
{
    std::cout << "ID = " << ID << std::endl;
};

MeterApolo::~MeterApolo()
{
    std::cout << "Meter Apolo Destructor " << ID << " begin called" << std::endl;
}
int MeterApolo::getIDMeter()
{
    return ID;
};

std::string MeterApolo::getNameMeter()
{
    return name;
};

