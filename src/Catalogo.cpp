#include "Catalogo.h"
#include "Meter.h"
#include "MeterAres.h"
#include "MeterZeus.h"

void Catalogo::addNewModel (std::string & type)
{
    auto p = factoryMeter(type);
    meter_model model{type, std::move(p)};

    lines_avaible.getList().push_back(std::move(model));
};

void Catalogo::removeModel (const int ID)
{
    lines_avaible.getList().remove_if([ID](const meter_model & model) {
        return model.meter->getIDMeter() == ID;
    });
}; 

void Catalogo::sortList()
{
    lines_avaible.getList().sort();
};    

Line & Catalogo::getLinesAvaible()
{
    sortList();
    return lines_avaible;
};

auto Catalogo::factoryMeter (std::string & type) -> std::unique_ptr<Meter>
{
    auto op = convertStringEnum(type);
    switch (op)
    {
    case Type::ARES :
        return std::unique_ptr<Meter>{new MeterAres};
        break;
    
    case Type::ZEUS :
        return std::unique_ptr<Meter>{new MeterZeus};
        break;

    default:
        break;
    }
};

Type Catalogo::convertStringEnum (std::string & type)
{
    if(type == "Ares") {return Type::ARES;}
    if(type == "Zeus") {return Type::ZEUS;}
}