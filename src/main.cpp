#include "grid/Catalog.h"
#include <iostream>
#include <memory>


int main()
{
    Catalog c;
    std::string name = "Oi";
    c.addNewModel(name);
    c.addNewModel(name);
    c.addNewModel(name);
    c.addNewModel(name);


    for (auto & cont : c.getAllModels().getList())
    {
       std::cout << cont->getID() << std::endl;
    }

    c.removeModel(3);

    for (auto & cont : c.getAllModels().getList())
    {
       std::cout << cont->getID() << std::endl;
    }
    return 0;
}