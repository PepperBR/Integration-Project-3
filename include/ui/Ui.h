#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include "core/Catalog.h"

struct MenuOptions 
{
    int op;
    std::string description;
    std::function<void()> menu_exec;
};

class Ui 
{
    public:
        void run();
        Ui();
    private:
        Catalog catalog;

        const std::vector<MenuOptions> menu_options;
        
        void exibirMenuTitle();
        void exibirMenuInicial();
        void exibirMenuLinhas();
        void limparInput();
        void listarModelosComId(bool is_template); //
        void exibirLinhasDisponiveis();
        void listarModelosPorLinha(); // 
        void listarTodosModelos(); //
        void menuAdicionarModelo();
        void menuRemoverModelo();
        void menuLeituraFases();
        void listarTodosModelosAdicionados();
        void exibirModelosLinha (std::string & linha);
        int collectUserOpInput();
        void finalizarPrograma();
};