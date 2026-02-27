#pragma once
#include "meters/Meter.h"
//Abstract Class
class Ares : public Meter
{
    private:
        int const ID;
        std::string name;
    public:
        std::string & getName() override;
        int getID() override;
        ~Ares() override;
        Ares(std::string _name);
};
