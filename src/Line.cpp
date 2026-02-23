#include "Line.h"

std::list<std::unique_ptr<Meter>> & Line::getList()
{
    return list;
};

std::unordered_map<std::string,std::list<std::unique_ptr<Meter>>> & Line::getListIndexedMeters()
{
    return list_indexed_meters;
};