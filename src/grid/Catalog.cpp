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
}

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

Line & Catalog::getLineModels(std::string type)
{
    Line list;
    sortList();
    for(auto & model : list_models.getList())
    {
        if(model->getName().find(type) != std::string::npos)
        {
            list.getList().push_back(std::move(model));
        }
    }
    return list;
};
