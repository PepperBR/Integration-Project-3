#include "grid/Catalog.h"
#include "meters/Apolo/Apolo6031.h"

Catalog::Catalog()
{
};

void Catalog::addNewModel (std::string & name)
{   
    auto model = factoryMeter(name);
    list_models.getList().push_back(std::move(model));
};

void Catalog::removeModel (const int ID)
{
    list_models.getList().remove_if([ID](std::unique_ptr<Meter> & meter) {
        return  meter->getID() == ID;
    });
}; 

std::vector<double> & Catalog::getMeasurementsPhases(const int ID)
{
    for (auto & cont  : list_models.getList())
    {
        if(cont->getID() == ID)
        {
            return cont->getPhaseValues();
        } 
    }

    throw std::runtime_error("Meter not found");
};

void Catalog::sortList()
{
    list_models.getList().sort(
        [](const std::unique_ptr<Meter>& meter_a,
            const std::unique_ptr<Meter>& meter_b)
        {
            return meter_a->getName() < meter_b->getName();
        });
};

Line & Catalog::getAllModels()
{
    sortList();
    return list_models;
};

auto Catalog::factoryMeter (std::string & name) -> std::unique_ptr<Meter>
{
    auto op = 1;
    switch (op)
    {
    case 1 :
        return std::unique_ptr<Meter>{new Apolo6031};
    default:
        break;
    }
};

std::list<std::string> & Catalog::getLines ()
{
    return lines;
};


std::list<Meter*> Catalog::getLineModels(const std::string & type) {
    std::list<Meter*> filtered; 
    for (auto & model : list_models.getList()) {
        if (model->getName().find(type) != std::string::npos) {
            filtered.push_back(model.get()); 
        }
    }
    return filtered; 
};

Modelo Catalog::convertStringEnum (std::string & type)
{
    if(type == "Apolo 6031") {return Modelo::Apolo6031;}
    if(type == "Ares 7021") {return Modelo::Ares7021;}
    if(type == "Ares 7031") {return Modelo::Ares7031;}
    if(type == "Ares 7023") {return Modelo::Ares7023;}
    if(type == "Ares 8023 15") {return Modelo::Ares8023_15;}
    if(type == "Ares 8023 200") {return Modelo::Ares8023_200;}
    if(type == "Ares 8023") {return Modelo::Ares8023;}
    if(type == "Cronos 6001 A") {return Modelo::Cronos6001_A;}
    if(type == "Cronos 6003") {return Modelo::Cronos6003;}
    if(type == "Cronos 6021 A") {return Modelo::Cronos6021_A;}
    if(type == "Cronos 6021 L") {return Modelo::Cronos6021_L;}
    if(type == "Cronos 7023 2.5") {return Modelo::Cronos7023_2_5;}
    if(type == "Cronos 7023 L") {return Modelo::Cronos7023_L;}
    if(type == "Cronos 7023") {return Modelo::Cronos7023;}
    if(type == "Zeus 8021") {return Modelo::Zeus8021;}
    if(type == "Zeus 8023") {return Modelo::Zeus8023;}
    if(type == "Zeus 8031") {return Modelo::Zeus8031;}
};
