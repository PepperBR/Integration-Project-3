#include "MeterAres.h"

MeterAres::MeterAres(std::string &_name, std::unique_ptr<Classification> _mode)
    : ID(GlobalID::generateID()),
      name(_name),
      mode(std::move(_mode))
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

const std::unique_ptr<Classification> & MeterAres::getMode()
{
    return mode;
}

