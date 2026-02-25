#include "MeterZeus.h"

MeterZeus::MeterZeus(std::string &_name, std::unique_ptr<Classification> _mode)
    : ID(GlobalID::generateID()),
      name(_name),
      mode(std::move(_mode))
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

const std::unique_ptr<Classification> & MeterZeus::getMode()
{
    return mode;
}

