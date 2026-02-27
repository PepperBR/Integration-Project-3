#pragma once

#include "meters/Meter.h"
#include <list>
#include <memory>

class Line
{
private:
    std::list<std::unique_ptr<Meter>> list;
public:
    std::list<std::unique_ptr<Meter>> & getList();
};