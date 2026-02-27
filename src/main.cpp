#include "Apolo/Apolo6031.h"
#include <iostream>
#include <memory>
#include "Meter.h"

int main()
{
    std::unique_ptr<Meter>n {new Apolo6031};

    for (auto & cont : n->getPhaseValues())
    {
        std::cout << cont << std::endl;
    }

    return 0;
}