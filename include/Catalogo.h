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
        Line list_models;
        std::list<std::string> lines {"Ares","Zeus","Cronos","Apolo"};
        auto factoryMeter (std::string & type, std::string & name) -> std::unique_ptr<Meter>;

    public:
        void addNewModel (std::string & type, std::string & name); 
        void removeModel (const int ID);                                                
        void sortList();                                                                
        Line & getListModels();       
        Type convertStringEnum (std::string & type);  
        std::list<std::string> & getLines ();
        Catalogo();
};
