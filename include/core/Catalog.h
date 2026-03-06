#pragma once

#include <list>
#include <memory>
#include <string>
#include <meters/Meter.h>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <tuple>

using LineList = std::set<std::string>;
using MetersList = std::list<std::unique_ptr<Meter>>;

class Catalog          
{
private:
    MetersList meter_list;
    std::unique_ptr<Meter> Catalog::factoryMeter(const int & ID_template); // testado
    void sortList(); // testado                        
    
public:
    void addNewModel (const int & ID_template); // testado
    bool removeModel (const int ID); // testado
    std::vector<double> & getMeasurementsPhases(const int ID); // TODO: testar
    
    LineList getLines () const; // testado
    std::vector<std::tuple<int, std::string, bool>> getLineModels(const std::string & line_name);// testado    
    
    Catalog();
};

