#include "MeterCronos.h"

MeterCronos::MeterCronos(std::string & _name, std::unique_ptr<Classification> _mode)
    : ID(GlobalID::generateID()),
      name(_name),
      mode(std::move(_mode))
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

const std::unique_ptr<Classification> & MeterCronos::getMode()
{
    return mode;
}