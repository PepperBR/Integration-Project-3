#include "GlobalID.h" 
#include "MeterAres.h" 
#include "MeterZeus.h" 
#include "Line.h"

int main()
{
    auto p1 = std::unique_ptr<Meter>{new MeterAres};    // ID = 0 
    auto p2 = std::unique_ptr<Meter>{new MeterAres};    // ID = 1
    auto p3 = std::unique_ptr<Meter>{new MeterZeus};    // ID = 2

    Line linha;
    /* auto & linha_diponivel = linha.getList();

    // linha_diponivel.push_back(p1); Faz uma cópia do p1, isso quebra o código, já que estamos usando unique_ptr
    linha_diponivel.push_back(std::move(p3)); // No caso, estamos utilizando o mesmo p1
    linha_diponivel.push_back(std::move(p2));
    linha_diponivel.push_back(std::move(p1)); */

    auto & linha_index_disponivel = linha.getListIndexedMeters();

    linha_index_disponivel.emplace("Ares", std::list<std::unique_ptr<Meter>>{});
    linha_index_disponivel["Ares"].push_back(std::move(p1));

    linha_index_disponivel.emplace("Zeus", std::list<std::unique_ptr<Meter>>{});
    linha_index_disponivel["Zeus"].push_back(std::move(p3));
    
    linha_index_disponivel.emplace("Ares", std::list<std::unique_ptr<Meter>>{});
    linha_index_disponivel["Ares"].push_back(std::move(p2));

    // imprimir cada meter
    /* for (const auto & meter : linha_diponivel)
    { 
        std::cout << meter->getIDMeter() << std::endl;
    } */

    for (const auto & type : linha_index_disponivel)
    {
        std::cout << type.first << std::endl;
        for (const auto & model : type.second)
        {
            std::cout << model->getIDMeter() << std::endl;
        }
    }
    return 0;
}