#include "grid/Catalog.h"
#include "meters/Apolo/Apolo6031.h"
#include "meters/Ares/Ares7021.h"
#include "meters/Ares/Ares7023.h"
#include "meters/Ares/Ares7031.h"
#include "meters/Ares/Ares8023.h"
#include "meters/Ares/Ares8023_15.h"
#include "meters/Ares/Ares8023_200.h"
#include "meters/Cronos/Cronos6001_A.h"
#include "meters/Cronos/Cronos6003.h"
#include "meters/Cronos/Cronos6021_A.h"
#include "meters/Cronos/Cronos6021_L.h"
#include "meters/Cronos/Cronos7023_2_5.h"
#include "meters/Cronos/Cronos7023_L.h"
#include "meters/Cronos/Cronos7023.h"
#include "meters/Zeus/Zeus8021.h"
#include "meters/Zeus/Zeus8023.h"
#include "meters/Zeus/Zeus8031.h"

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
    auto meter = convertStringEnum(name);
    switch (meter)
    {
    case Modelo::Apolo6031 :
        return std::unique_ptr<Meter>{new Apolo6031};
    case Modelo::Ares7021 :
        return std::unique_ptr<Meter>{new Ares7021};
    case Modelo::Ares7031 :
        return std::unique_ptr<Meter>{new Ares7031};
    case Modelo::Ares7023 :
        return std::unique_ptr<Meter>{new Ares7023};
    case Modelo::Ares8023_15 :
        return std::unique_ptr<Meter>{new Ares8023_15};
    case Modelo::Ares8023_200 :
        return std::unique_ptr<Meter>{new Ares8023_200};
    case Modelo::Ares8023 :
        return std::unique_ptr<Meter>{new Ares8023};
    case Modelo::Cronos6001_A :
        return std::unique_ptr<Meter>{new Cronos6001_A};
    case Modelo::Cronos6003 :
        return std::unique_ptr<Meter>{new Cronos6003};
    case Modelo::Cronos6021_A :
        return std::unique_ptr<Meter>{new Cronos6021_A};
    case Modelo::Cronos6021_L :
        return std::unique_ptr<Meter>{new Cronos6021_L};
    case Modelo::Cronos7023_2_5 :
        return std::unique_ptr<Meter>{new Cronos7023_2_5};
    case Modelo::Cronos7023_L :
        return std::unique_ptr<Meter>{new Cronos7023_L};
    case Modelo::Cronos7023 :
        return std::unique_ptr<Meter>{new Cronos7023};
    case Modelo::Zeus8021 :
        return std::unique_ptr<Meter>{new Zeus8021};
    case Modelo::Zeus8023 :
        return std::unique_ptr<Meter>{new Zeus8023};
    case Modelo::Zeus8031 :
        return std::unique_ptr<Meter>{new Zeus8031};    
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
