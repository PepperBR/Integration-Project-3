#include "grid/Line.h"

std::list<std::unique_ptr<Meter>> & Line::getList()
{
    return list;
}