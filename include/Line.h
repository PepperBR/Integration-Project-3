#pragma once
#include "Meter.h"
#include <list>
#include <unordered_map>
#include <memory>

struct meter_model{
    std::string type;
    std::unique_ptr<Meter> meter;

};

class Line
{
    private:
        std::list<meter_model> list;
    public:
        std::list<meter_model> & getList();
};