#include "GlobalID.h" 
#include "MeterAres.h" 
#include "MeterZeus.h"
#include "MeterCronos.h" 
#include "MeterApolo.h" 
#include "Line.h"
#include "Catalogo.h"

int main()
{   
    Catalogo catalogo;
    std::string ares = "Ares";
    std::string zeus = "Zeus";

    catalogo.addNewModel(ares); 
    catalogo.addNewModel(zeus);
    catalogo.addNewModel(zeus);
    catalogo.addNewModel(zeus);
    catalogo.addNewModel(zeus);
    catalogo.addNewModel(zeus);
    catalogo.addNewModel(ares);

    catalogo.removeModel(1);
    catalogo.removeModel(2);
    catalogo.removeModel(3);
    catalogo.removeModel(4);
    catalogo.removeModel(5);

    for (auto & models : catalogo.getLinesAvaible().getList())
    {
        std::cout << models.type << std::endl;
    }
    
    return 0;
}