#pragma once
#include "Line.h"

enum class Type
{
    ARES,
    ZEUS,
    APOLO,
    CRONOS,
};


class Catalogo          
{
    private:
        Line lines_avaible;
        auto factoryMeter (std::string & type) -> std::unique_ptr<Meter>;

    public:
        void addNewModel (std::string & type); 
        void removeModel (const int ID);                                                
        void sortList();                                                                
        Line & getLinesAvaible();       
        Type convertStringEnum (std::string & type);                 

};
