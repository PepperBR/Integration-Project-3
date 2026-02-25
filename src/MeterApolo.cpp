#include "MeterApolo.h"

MeterApolo::MeterApolo(std::string &_name, std::unique_ptr<Classification> _mode)
    : ID(GlobalID::generateID()),
      name(_name),
      mode(std::move(_mode))
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

const std::unique_ptr<Classification> & MeterApolo::getMode()
{
    return mode;
}