#pragma once
#include "Meter.h"
#include <list>
#include <unordered_map>
#include <memory>

class Line
{
    private:
        std::list<std::unique_ptr<Meter>> list;
        std::unordered_map<std::string,std::list<std::unique_ptr<Meter>>> list_indexed_meters;

    public:
        std::list<std::unique_ptr<Meter>> & getList();
        std::unordered_map<std::string,std::list<std::unique_ptr<Meter>>> & getListIndexedMeters();

};