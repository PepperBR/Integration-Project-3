#include "Catalogo.h"
#include "Meter.h"
#include "MeterAres.h"
#include "MeterZeus.h"
#include "MeterCronos.h"
#include "MeterApolo.h"
#include "Classification.h"
#include "SinglePhase.h"
#include "TwoPhase.h"
#include "ThreePhase.h"

Catalogo::Catalogo()
{
    std::string ares = "Ares";
    std::string zeus = "Zeus";
    std::string cronos = "Cronos";
    std::string apolo = "Apolo";

    std::string name = "Ares 7021";
    int mode = 1;

    addNewModel(ares,std::move(name),mode);
    name = "Zeus 8021"; 

};

void Catalogo::addNewModel (std::string & type, std::string & name, int & mode)
{   
    auto classification_mode = factoryClassification(mode);
    auto p = factoryMeter(type, name, classification_mode);
    meter_model model{type, std::move(p)};

    list_models.getList().push_back(std::move(model));
};

void Catalogo::removeModel (const int ID)
{
    list_models.getList().remove_if([ID](const meter_model & model) {
        return model.meter->getIDMeter() == ID;
    });
}; 

const int & Catalogo::getMeasurementPhaseA(const int ID)
{
    for (auto & cont  : list_models.getList())
    {
        if(cont.meter->getIDMeter() == ID)
        {
            return cont.meter->getMode()->measurementPhaseA();
        } 
    }
    return -1;
}

const int & Catalogo::getMeasurementPhaseB(const int ID)
{
    for (auto & cont  : list_models.getList())
    {
        if(cont.meter->getIDMeter() == ID)
        {
            return cont.meter->getMode()->measurementPhaseB();
        } 
    }
}

const int & Catalogo::getMeasurementPhaseC(const int ID)
{
    for (auto & cont  : list_models.getList())
    {
        if(cont.meter->getIDMeter() == ID)
        {
            return cont.meter->getMode()->measurementPhaseC();
        } 
    }
}
void Catalogo::sortList()
{
    list_models.getList().sort();
};    

Line & Catalogo::getListModels()
{
    sortList();
    return list_models;
};

auto Catalogo::factoryMeter (std::string & type , std::string & name, std::unique_ptr<Classification> & mode) -> std::unique_ptr<Meter>
{
    auto op = convertStringEnum(type);
    switch (op)
    {
    case Type::ARES :
        return std::unique_ptr<MeterAres>{new MeterAres(name, std::move(mode))};
    
    case Type::ZEUS :
        return std::unique_ptr<MeterZeus>{new MeterZeus(name, std::move(mode))};
    
    case Type::CRONOS :
        return std::unique_ptr<MeterCronos>{new MeterCronos(name, std::move(mode))};
    
    case Type::APOLO :
        return std::unique_ptr<MeterApolo>{new MeterApolo(name, std::move(mode))};

    default:
        break;
    }
};
auto Catalogo::factoryClassification(int & op) -> std::unique_ptr<Classification>
{
    switch (op)
    {
    case 1:
        return std::unique_ptr<Classification>{new SinglePhase};

    case 2:
        return std::unique_ptr<Classification>{new TwoPhase};

    case 3:
        return std::unique_ptr<Classification>{new ThreePhase};

    default:
        break;
    }
};

std::list<std::string> & Catalogo::getLines ()
{
    return lines;
};

Type Catalogo::convertStringEnum (std::string & type)
{
    if(type == "Ares") {return Type::ARES;}
    if(type == "Zeus") {return Type::ZEUS;}
    if(type == "Apolo") {return Type::APOLO;}
    if(type == "Cronos") {return Type::CRONOS;}
};

