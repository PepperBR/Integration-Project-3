#include "core/Catalog.h"
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

/*
    - Planejamento:
    -> Modificar Meter
        -> Ajustar para aceitar template (True/False) [X] 
        -> Adicionar name_Line , name_Model/ getFullName(), getNameLine() e getNameModel() [X]
        -> Modificar para ser possível fazer uma cópia extra de um objeto do Meter, modificando ID e colocando 
        template como False [X]
        -> Fazer a leitura de Fases Funcionar [] depois
    -> Modificar Catalog
        -> Ajustar para quando cirar uma deep copy, ser ajustado a variável is_template (True   ) []
        -> Com a mudança em como vai ficar Meter, vai ser necessário alterar todos os métodos para essa mudança de comportamento []
    -> Modificar Ui
        -> Com a mudança em como vai ficar Catalog,  vai ser necessário alterar todos os métodos para essa mudança de comportamento []
*/
Catalog::Catalog()
{
    meter_list.emplace_back(std::make_unique<Apolo6031>());
    
    meter_list.emplace_back(std::make_unique<Zeus8021>());
    meter_list.emplace_back(std::make_unique<Zeus8023>());
    meter_list.emplace_back(std::make_unique<Zeus8031>());
    
    meter_list.emplace_back(std::make_unique<Cronos7023>());
    meter_list.emplace_back(std::make_unique<Cronos7023_L>());
    meter_list.emplace_back(std::make_unique<Cronos7023_2_5>());
    meter_list.emplace_back(std::make_unique<Cronos6021_L>());
    meter_list.emplace_back(std::make_unique<Cronos6021_A>());
    meter_list.emplace_back(std::make_unique<Cronos6003>());
    meter_list.emplace_back(std::make_unique<Cronos6001_A>());

    meter_list.emplace_back(std::make_unique<Ares7021>());
    meter_list.emplace_back(std::make_unique<Ares8023>());
    meter_list.emplace_back(std::make_unique<Ares7023>());
    meter_list.emplace_back(std::make_unique<Ares7031>());
    meter_list.emplace_back(std::make_unique<Ares8023_15>());
    meter_list.emplace_back(std::make_unique<Ares8023_200>());
};

void Catalog::addNewModel (const int & ID_template)
{   
    auto model = factoryMeter(ID_template);
    meter_list.push_back(std::move(model));
    sortList();
};

void Catalog::removeModel (const int ID)
{
    meter_list.remove_if([ID](std::unique_ptr<Meter> & meter_list) {
        return  meter_list->getID() == ID && !meter_list->getIsTemplate() ;
    });
}; 

std::vector<double> & Catalog::getMeasurementsPhases(const int ID)
{
/*     for (auto & cont  : meters)
    {
        if(cont->getID() == ID)
        {
            return cont->getPhaseValues();
        } 
    }
 */
    throw std::runtime_error("Meter not found");
};

void Catalog::sortList()
{
    meter_list.sort(
        [](const std::unique_ptr<Meter>& meter_a,
            const std::unique_ptr<Meter>& meter_b)
        {
            return meter_a->getFullName() < meter_b->getFullName();
        });
};

std::unique_ptr<Meter> Catalog::factoryMeter(const int & ID_template)
{
    for (const auto& meter_template : meter_list) {
        if (meter_template->getID() == ID_template && meter_template->getIsTemplate()) {
            return meter_template->cloneMeter();
        }
    }
    return nullptr; 
}

LineList Catalog::getLines() const
{
    std::set<std::string> lines;
    
    for (const auto & meter  : meter_list)
    {
        lines.insert(meter->getNameLine());
    }   
   
    return lines;
}


std::vector<std::tuple<int, std::string, bool>> Catalog::getLineModels(const std::string & name_line) 
{
    std::vector<std::tuple<int, std::string, bool>> list;

    for (auto & model : meter_list) {
        if (model->getFullName().find(name_line) != std::string::npos) {
            list.push_back({model->getID(), model->getFullName(), model->getIsTemplate()});
        }
    }
    
    return list; 
}
