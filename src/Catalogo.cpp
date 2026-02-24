#include "Catalogo.h"
#include "Meter.h"
#include "MeterAres.h"
#include "MeterZeus.h"
#include "MeterCronos.h"
#include "MeterApolo.h"

Catalogo::Catalogo()
{
    std::string ares = "Ares";
    std::string zeus = "Zeus";
    std::string cronos = "Cronos";
    std::string apolo = "Apolo";

    std::string name = "Ares 7021";
    addNewModel(ares,std::move(name));
    name = "Zeus 8021"; 
    addNewModel(zeus,std::move(name));
    name = "Zeus 8031"; 
    addNewModel(zeus,std::move(name));
    name = "Zeus 8041"; 
    addNewModel(zeus,std::move(name));
    name = "Zeus 8051"; 
    addNewModel(zeus,std::move(name));
    name = "Zeus 8061"; 
    addNewModel(zeus,std::move(name)); 
    name = "Ares 8021";
    addNewModel(ares,std::move(name));

};

void Catalogo::addNewModel (std::string & type, std::string & name)
{
    auto p = factoryMeter(type, name);
    meter_model model{type, std::move(p)};

    list_models.getList().push_back(std::move(model));
};

void Catalogo::removeModel (const int ID)
{
    list_models.getList().remove_if([ID](const meter_model & model) {
        return model.meter->getIDMeter() == ID;
    });
}; 

void Catalogo::sortList()
{
    list_models.getList().sort();
};    

Line & Catalogo::getListModels()
{
    sortList();
    return list_models;
};

auto Catalogo::factoryMeter (std::string & type , std::string & name) -> std::unique_ptr<Meter>
{
    auto op = convertStringEnum(type);
    switch (op)
    {
    case Type::ARES :
        return std::unique_ptr<MeterAres>{new MeterAres(name)};
    
    case Type::ZEUS :
        return std::unique_ptr<MeterZeus>{new MeterZeus(name)};
    
    case Type::CRONOS :
        return std::unique_ptr<MeterCronos>{new MeterCronos(name)};
    
    case Type::APOLO :
        return std::unique_ptr<MeterApolo>{new MeterApolo(name)};

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
};