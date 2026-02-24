#pragma once
#include "Catalogo.h"

class Ui
{
    private:
        Catalogo catalogo;
        void exibir_menu_inicial();
        void exibir_menu_linhas();

    public:
        Ui();
        void run();
};
