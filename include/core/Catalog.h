#pragma once

#include <list>
#include <memory>
#include <string>
#include <meters/Meter.h>
#include <unordered_map>
#include <set>
#include <algorithm>

using LineList = std::set<std::string>;
using Line = std::list<std::unique_ptr<Meter>>;
using MetersList = std::list<std::unique_ptr<Meter>>;

class Catalog          
{
private:
    Line meters;
    MetersList meter_list;
    std::unique_ptr<Meter> Catalog::factoryMeter(const std::string& name); // testado
    
public:
    void addNewModel (const std::string & name); // testado
    void removeModel (const int ID); // testado
    std::vector<double> & getMeasurementsPhases(const int ID); // realizar medições [AJUSTAR] 
    
    void sortList(); // testado                        
    LineList getLines () const; // testado
    std::vector<std::pair<int, std::string>> getLineModels(const std::string & line_name);// testado    


    Catalog();
};

