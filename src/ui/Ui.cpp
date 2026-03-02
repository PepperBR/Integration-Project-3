#include "ui/Ui.h"
#include <string>
#include <iostream>
#include <limits>

void Ui::limparInput() {
    std::cin.clear();
    std::cin.ignore();
}

void Ui::run() {
    int op;
    while (true) {
        exibirMenuInicial();
        if (!(std::cin >> op)) 
        {
            std::cout << "Opção inválida!\n";
            limparInput();
            continue;
        }

        if (op == 7)
        {
          break;  
        } 

        switch (op) 
        {
            case 1: 
                listarModelosPorLinha();   
                break;
            case 2: 
                exibirLinhasDisponiveis(); 
                break;
            case 3: 
                listarTodosModelos();      
                break;
            case 4: 
                menuAdicionarModelo();     
                break;
            case 5: 
                menuRemoverModelo();       
                break;
            case 6: 
                menuLeituraFases();        
                break;
            default: 
                std::cout << "Opção inexistente.\n";
                std::cout << "Aperte Enter para continuar.\n";
                std::cin.ignore();
                
                break;
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

void Ui::listarModelosComId() {
    std::cout << "\nID   |   Nome do modelo\n";
    std::cout << "--------------------------\n";
    for (auto & meter : catalog.getAllModels())
    {
        std::cout << meter->getID() << "          " << meter->getName() << "\n";
    }
}

void Ui::listarModelosPorLinha() {
    exibirMenuLinhas();
    std::string nomeLinha;
    std::cin >> nomeLinha;

    std::cout << "\n=== Modelos da Linha " << nomeLinha << " ===\n";
    auto modelos_linha = catalog.getLineModels(nomeLinha);
    if (modelos_linha.size() == 0){
        std::cout << "Nenhum modelo encontrado nesta linha.\n";
    }else{
        for(auto & modelo : modelos_linha)
        {
            std::cout << modelo->getName() << std::endl;
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
            std::cout << modelo->getName() << "         " << modelo->getID() << "\n";
        }
    }

    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::menuAdicionarModelo() {
    //Exibição linhas disponíveis
    exibirLinhasDisponiveis();
    std::string type, name;

    std::cout << "\nEscolha a linha: ";
    std::cin >> type;

    bool existe = false;
    for (const auto & line : catalog.getLines())
    {
        if (line == type){
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
    //
    exibirModelosLinha(type);

    //Verifica se o modelo escolhido existe
    
    std::cout << "\nDigite o nome do novo modelo que deseja criar: ";
    limparInput();
    std::getline(std::cin, name);
    auto const models = catalog.getModels();

    existe = false;
    for (const auto & modelo :  models.at(type))
    {
        if(name == modelo)
        {
            existe = true;
            break;
        }
    }

    if(existe)
    {
        catalog.addNewModel(type + " " + name);
        std::cout << "Modelo adicionado com sucesso!\n";
    }else{
        std::cout << "Escreva um Modelo que pertence a linha.\n";
    }
    limparInput();
    std::cout << "Aperte Enter para continuar.\n";
    std::cin.ignore();
}

void Ui::menuRemoverModelo() {
    listarModelosComId();
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
    listarModelosComId();
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

// --- Menus de Texto ---

void Ui::exibirMenuInicial() {
    std::cout << "\n==============================";
    std::cout << "\n       MENU PRINCIPAL";
    std::cout << "\n==============================";
    std::cout << "\n(1) Filtrar modelos por linha"
              << "\n(2) Ver todas as linhas"
              << "\n(3) Ver catálogo completo"
              << "\n(4) Adicionar novo modelo"
              << "\n(5) Remover modelo"
              << "\n(6) Ler medição de fase"
              << "\n(7) Sair"
              << "\nEscolha: ";
}

void Ui::exibirMenuLinhas() {
    std::cout << "\n--- Digite o nome de uma das linhas abaixo ---\n";
    for (const auto & linha : catalog.getLines()) 
    {
        std::cout << "  [" << linha << "]";
    }
    std::cout << "\nLinha: ";
}

void Ui::exibirModelosLinha (std::string & linha) {
    std::cout << "\n--- Modelos da Linha Selecionada ---\n";
    auto const modelos = catalog.getModels();
    for (const auto & modelo :  modelos.at(linha))
    {
        std::cout << "  [" << modelo << "]";
    }
}