#include "MeterCronos.h"

MeterCronos::MeterCronos()
    : ID(GlobalID::generateID())
{
    std::cout << "ID = " << ID << std::endl;
};

MeterCronos::~MeterCronos()
{
    std::cout << "Meter Cronos Destructor " << ID << " begin called" << std::endl;
}
int MeterCronos::getIDMeter()
{
    return ID;
};

std::string MeterCronos::getNameMeter()
{
    return name;
};

