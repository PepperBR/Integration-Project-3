#pragma once
#include "Meter.h"
#include <list>
#include <unordered_map>
#include <memory>

struct meter_model{
    std::string type;
    std::unique_ptr<Meter> meter;

    bool operator < (const meter_model& other_model) const {
        return type < other_model.type;
    }
};

class Line
{
    private:
        std::list<meter_model> list;
    public:
        std::list<meter_model> & getList();
};