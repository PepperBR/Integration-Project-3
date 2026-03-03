#include "meters/Zeus/Zeus8031.h"
#include "core/GlobalID.h"
#include <iostream>

Zeus8031::Zeus8031()
    : Zeus(GlobalID::generateID(), "8031")
{
};

Zeus8031::~Zeus8031()
{
    std::cout << "Zeus 8031 Meter Destructor is begin called" << std::endl;
};

std::vector<double> & Zeus8031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Zeus8031::createMeter(int new_id) const
{
    return std::make_unique<Zeus8031>();
}

std::unique_ptr<Meter> Zeus8031::cloneMeter() const
{
    return std::make_unique<Zeus8031>(*this);
}


