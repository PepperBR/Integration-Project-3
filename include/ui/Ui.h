#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grid/Catalog.h" 

class Ui 
{
    public:
        void run();

    private:
        Catalog catalog;

        void exibirMenuInicial();
        void exibirMenuLinhas();
        void limparInput();
        void listarModelosComId(); //
        void exibirLinhasDisponiveis();
        void listarModelosPorLinha(); // 
        void listarTodosModelos(); //
        void menuAdicionarModelo();
        void menuRemoverModelo();
        void menuLeituraFases();
        void exibirModelosLinha (std::string & linha);
};