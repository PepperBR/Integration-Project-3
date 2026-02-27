#pragma once
#include "grid/Line.h"
enum class Modelo{
    Apolo6031,
    Ares7021,
    Ares7031,
    Ares7023,
    Ares8023_15,
    Ares8023_200,
    Ares8023,
    Cronos6001_A,
    Cronos6003,
    Cronos6021_A,
    Cronos6021_L,
    Cronos7023_2_5,
    Cronos7023_L,
    Cronos7023,
    Zeus8021,
    Zeus8023,
    Zeus8031
};

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
    std::list<Meter*> getLineModels(const std::string & type);// pegar todos os modelos de uma linha especíca organizado
    Modelo convertStringEnum (std::string & type); // converter
    Catalog();
};

