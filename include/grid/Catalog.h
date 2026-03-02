#pragma once

#include <list>
#include <memory>
#include <string>
#include <meters/Meter.h>
#include <unordered_map>

enum class Modelo
{
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


using LineList = std::list<std::string>;
using Line = std::list<std::unique_ptr<Meter>>;
using Meters = std::vector<Meter*>;

class Catalog          
{
private:
    Line meters;
    LineList lines {"Ares","Zeus","Cronos","Apolo"}; // TODO: transformar em enum
    static std::unordered_map<std::string, std::vector<std::string>> const models;
    std::unique_ptr<Meter> factoryMeter(const std::string& name);
    Meters meter_list;
public:
    void addNewModel (const std::string & name); // adicionar
    void removeModel (const int ID); // remover
    std::vector<double> & getMeasurementsPhases(const int ID); // realizar medições
    
    void sortList(); // auxiliar na hora de deixar a lista dos modelos ordenada                                  
    Line & getAllModels(); // pegar todos os modelos organizado
    const LineList & getLines () const; // pegar todas as linhas
    Meters getLineModels(const std::string & type);// pegar todos os modelos de uma linha especíca organizado
    Modelo convertStringEnum (const std::string & type); // converter
    static const std::unordered_map<std::string,std::vector<std::string>> getModels ();
    Catalog();
};

