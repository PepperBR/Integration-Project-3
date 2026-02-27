#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "grid/Catalog.h"

class Ui
{
    private:
        Catalog catalog;

        void exibir_menu_inicial();
        void exibir_menu_linhas();
        void limparInput();
        void listarModelosComId();
        void exibirLinhasDisponiveis();
        void listarModelosPorLinha();
        void listarTodosModelos();
        void menuAdicionarModelo();
        void menuRemoverModelo();
        void menuLeituraFases();

    public:
        void run();

};
