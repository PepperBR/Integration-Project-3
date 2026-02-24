#include "MeterCronos.h"

MeterCronos::MeterCronos(std::string & _name)
    : ID(GlobalID::generateID()),
      name(_name)
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

