#pragma once
#include "meters/Meter.h"
//Abstract Class
class Cronos : public Meter
{
    private:
        int const ID;
        std::string name;
    public:
        std::string & getName() override;
        int getID() override;
        ~Cronos() override;
        Cronos(std::string _name);
};
