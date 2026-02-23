#include "MeterApolo.h"

MeterApolo::MeterApolo()
    : ID(GlobalID::generateID())
{
    std::cout << "ID = " << ID << std::endl;
};

MeterApolo::~MeterApolo()
{
    std::cout << "Meter Zeus Destructor " << ID << " begin called" << std::endl;
}
int MeterApolo::getIDMeter()
{
    return ID;
};

std::string MeterApolo::getNameMeter()
{
    return name;
};

