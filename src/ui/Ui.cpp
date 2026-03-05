#include "ui/Ui.h"
#include <string>
#include <iostream>
#include <limits>
#include <tuple>

static bool execute = true;

Ui::Ui()
    : menu_options({
    MenuOptions
    {1, "Filtrar modelos por linha", [this] () {listarModelosPorLinha(); }},
    {2, "Ver todas as linhas", [this] () {exibirLinhasDisponiveis(); }},
    {3, "Ver catálogo de opções", [this] () {listarTodosModelos(); }},
    {4, "Ver catálogo de modelos adicionados", [this] () {listarTodosModelosAdicionados(); }},
    {5, "Adicionar novo modelo", [this] () {menuAdicionarModelo(); }},
    {6, "Remover modelo", [this] () {menuRemoverModelo(); }},
    {7, "Ler medição de fase", [this] () {menuLeituraFases(); }},
    {8, "Sair", [this] () {finalizarPrograma(); }}
}){}

void Ui::limparInput() {
    
    std::cin.clear();
    std::cin.ignore();
}


void Ui::run() {
    while (execute) {

        exibirMenuInicial();
        auto option = collectUserOpInput();

        for (const auto &seletected_menu : menu_options)
        {
            if(option == seletected_menu.op)
            {
                seletected_menu.menu_exec();
            }
        }
    }
}


void Ui::exibirLinhasDisponiveis() {
    std::cout << "\n=== Linhas Existentes ===\n";
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "- " << linha << "\n";
    }
}

void Ui::listarModelosComId(bool is_template) {
    std::cout << "\nID   |   Nome do modelo\n";
    std::cout << "--------------------------\n";
    for (const auto & line : catalog.getLines())
    {
        for (const auto & meter : catalog.getLineModels(line))
        {
            if(is_template == std::get<2>(meter))
            {
                std::cout << std::get<0>(meter) << "          " << std::get<1>(meter) << "\n";
            }
        }
    }
}

void Ui::listarModelosPorLinha() {
    exibirMenuLinhas();

    std::string nomeLinha;
    limparInput();
    std::getline(std::cin, nomeLinha);

    std::cout << "\n=== Modelos da Linha " << nomeLinha << " ===\n";
    auto modelos_linha = catalog.getLineModels(nomeLinha);
    if (modelos_linha.size() == 0){
        std::cout << "Nenhum modelo encontrado nesta linha.\n";
    }else{
        for(auto & modelo : modelos_linha)
        {
            std::cout << std::get<1>(modelo) << std::endl;
        }
    }

    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::listarTodosModelos() {
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "\n=== Linha: " << linha << " ===\n";
        auto modelos_linha = catalog.getLineModels(linha);
        for(auto & modelo : modelos_linha)
        {
            if(std::get<2>(modelo))
            {
                std::cout << std::get<0>(modelo) << " | " << std::get<1>(modelo) << "\n";
            }
        }
    }

    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::listarTodosModelosAdicionados() {
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "\n=== Linha: " << linha << " ===\n";
        auto modelos_linha = catalog.getLineModels(linha);
        for(auto & modelo : modelos_linha)
        {
            if(!std::get<2>(modelo))
            {
                std::cout << std::get<0>(modelo) << " | " << std::get<1>(modelo) << "\n";
            }
        }
    }

    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}



void Ui::menuAdicionarModelo() {
    exibirLinhasDisponiveis();
    std::string line, name;

    std::cout << "\nEscolha a linha: ";
    std::getline(std::cin, line);

    bool existe = false;
    for (const auto & linha : catalog.getLines())
    {
        if (linha == line){
            existe = true;
        }   
    }
    if (!existe) {
        limparInput();
        std::cout << "Erro: Linha inválida.\n";
        std::cout << "Aperte Enter para continuar.\n";
        std::cin.ignore();
        return;
    }

    exibirModelosLinha(line);

    std::cout << "\nDigite o ID do template que deseja criar um novo modelo : ";
    limparInput();
    auto option_ID = collectUserOpInput();
    const auto models = catalog.getLineModels(line);

    existe = false;
    for (const auto & modelo :  models)
    {
        if(option_ID == std::get<0>(modelo))
        {
            existe = true;
            break;
        }
    }

    if(existe)
    {
        catalog.addNewModel(option_ID);
        std::cout << "Modelo adicionado com sucesso!\n";
    }else{
        std::cout << "Escolha um Modelo que pertence a linha.\n";
    }
    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::menuRemoverModelo() {
    listarModelosComId(false);
    int id;
    std::cout << "\nID para remover: ";
    if (std::cin >> id) {
        catalog.removeModel(id);
    } else {
        std::cout << "\nDigite um ID correto.";
    }

    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::menuLeituraFases() {
    listarModelosComId(true);
    int id;
    
    std::cout << "ID do medidor que deseja realizar as leituras: ";
    if (!(std::cin >> id))
    { 
        std::cout << "Digite uma opção vália.\n";
        limparInput();
        std::cout << "Aperte Enter para continuar.\n";
        std::cin.ignore();
        return; 
    }
    
    auto measurements = catalog.getMeasurementsPhases(id);
    for(int cont = 0; cont < measurements.size(); cont++)
    {
        std::cout << "A leitura da " << cont + 1 << "° fase é : " << measurements[cont ] << "\n";
    }
    
    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::exibirMenuTitle() 
{
    std::cout << "\n==============================";
    std::cout << "\n       MENU PRINCIPAL";
    std::cout << "\n==============================\n";
}

void Ui::exibirMenuInicial() 
{   
    exibirMenuTitle();
    for (const auto &menu_item : menu_options)
    {
        std::cout << menu_item.op << "\t" << menu_item.description << "\n";
    }
    std::cout << "Escolha uma opção: " << std::endl;
}

void Ui::exibirMenuLinhas() {
    std::cout << "\n--- Digite o nome de uma das linhas abaixo ---\n";
    for (const auto & linha : catalog.getLines()) 
    {
        std::cout << " [" << linha << "] ";
    }
    std::cout << "Linha: ";
}

void Ui::exibirModelosLinha (std::string & linha) {
    std::cout << "\n--- Modelos da Linha Selecionada ---\n";
    auto const modelos = catalog.getLineModels(linha);
    for (const auto & modelo :  modelos)
    {
        std::cout << "(" << std::get<0>(modelo) << ") - " << std::get<1>(modelo) << "\n";
    }
}

int Ui::collectUserOpInput()
{
    int option;

    if (!(std::cin >> option)) 
    {
        return -1;
    }

    return option;
}

void Ui::finalizarPrograma() {
    execute = false;
}