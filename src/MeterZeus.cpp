#include "MeterZeus.h"

MeterZeus::MeterZeus()
    : ID(GlobalID::generateID())
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

