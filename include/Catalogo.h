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
        auto factoryMeter (std::string & type, std::string & name, std::unique_ptr<Classification> & mode) -> std::unique_ptr<Meter>;
        auto factoryClassification(int & op) -> std::unique_ptr<Classification>;

    public:
        void addNewModel (std::string & type, std::string & name, int & mode); 
        void removeModel (const int ID);
        const int & getMeasurementPhaseA(const int ID);
        const int & getMeasurementPhaseB(const int ID);  
        const int & getMeasurementPhaseC(const int ID);                                       
        void sortList();                                                                
        Line & getListModels();       
        Type convertStringEnum (std::string & type);  
        std::list<std::string> & getLines ();
        Catalogo();
};
