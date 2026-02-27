#pragma once
#include "meters/Meter.h"
//Abstract Class
class Apolo : public Meter
{
    private:
        int const ID;
        std::string name;
    public:
        std::string & getName() override;
        int getID() override;
        ~Apolo() override;
        Apolo(std::string _name);
};

