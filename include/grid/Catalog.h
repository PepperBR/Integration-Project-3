#pragma once
#include "grid/Line.h"

class Catalog          
{
    private:
        Line list_models;
        std::list<std::string> lines {"Ares","Zeus","Cronos","Apolo"};
        auto factoryMeter (std::string & name) -> std::unique_ptr<Meter>;

    public:
        void addNewModel (std::string & name); // adicionar
        void removeModel (const int ID); // remover
        std::vector<double> & getMeasurementsPhases(const int ID); // realizar medições

        void sortList(); // auxiliar na hora de deixar a lista dos modelos ordenada                                  
        Line & getAllModels(); // pegar todos os modelos organizado
        std::list<std::string> & getLines (); // pegar todas as linhas
        Line & getLineModels(std::string type);// pegar todos os modelos de uma linha especíca organizado
        Catalog();
};
