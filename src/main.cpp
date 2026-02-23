#include "GlobalID.h" 
#include "MeterAres.h" 
#include "MeterZeus.h"
#include "MeterCronos.h" 
#include "MeterApolo.h" 
#include "Line.h"
#include <algorithm>


int main()
{
    auto p1 = std::unique_ptr<Meter>{new MeterAres};    // ID = 0 
    auto p2 = std::unique_ptr<Meter>{new MeterAres};    // ID = 1

    auto p3 = std::unique_ptr<Meter>{new MeterZeus};    // ID = 2

    /* auto p4 = std::unique_ptr<Meter>{new MeterCronos};    // ID = 3 
    auto p5 = std::unique_ptr<Meter>{new MeterCronos};    // ID = 4
    
    auto p6 = std::unique_ptr<Meter>{new MeterApolo};    // ID = 5
    auto p7 = std::unique_ptr<Meter>{new MeterApolo};    // ID = 6 
    auto p8 = std::unique_ptr<Meter>{new MeterApolo};    // ID = 7
    auto p9 = std::unique_ptr<Meter>{new MeterApolo};    // ID = 8 */

    meter_model modelo1{"Ares",std::move(p1)};
    meter_model modelo2{"Ares",std::move(p2)};

    meter_model modelo3{"Zeus",std::move(p3)};

    Line linha;

    // AddNewModel
    auto & linha_diponivel = linha.getList();


    linha_diponivel.push_back(std::move(modelo1));
    linha_diponivel.push_back(std::move(modelo2));
    linha_diponivel.push_back(std::move(modelo3));

    // RemoveModel
    auto ne = remove_if(linha_diponivel.begin(), linha_diponivel.end(),
                        [](meter_model & model) {
                            return model.meter->getIDMeter() == 7;
                        });
    linha_diponivel.erase(ne, linha_diponivel.end());
    // imprimir cada meter
    for (const auto & meter : linha_diponivel)
    { 
        std::cout << meter.type << std::endl;
    } 
    return 0;
}