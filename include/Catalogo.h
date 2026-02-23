#pragma once
#include "Line.h"

class Catalogo
{
    private:
        Line lines_avaible;
    public:
        Catalogo(/* args */);
        void addNewModel (std::string & meter_type, std::unique_ptr<Meter> new_meter); // Sei como fazer
        void removeModel (const int ID); // Falta descobrir
};
