#include "ui/Ui.h"
#include <string>
#include <iostream>
#include <limits>

void Ui::limparInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Ui::run() {
    int op;
    while (true) {
        exibir_menu_inicial();
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
                break;
        }
    }
}

// --- Métodos de Apoio (Visualização) ---

void Ui::exibirLinhasDisponiveis() {
    std::cout << "\n=== Linhas Existentes ===\n";
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "- " << linha << "\n";
    }
}

void Ui::listarModelosComId() {
    std::cout << "\nNome do modelo   |   ID\n";
    std::cout << "--------------------------\n";
    for (auto & meter : catalog.getAllModels().getList())
    {
        std::cout << meter->getName() << "    " << meter->getID() << "\n";
    }
}

// --- Sub-Menus (Lógica de Negócio) ---

void Ui::listarModelosPorLinha() {
    exibir_menu_linhas();
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
}

void Ui::listarTodosModelos() {
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "\n=== Linha: " << linha << " ===\n";
        auto modelos_linha = catalog.getLineModels(linha);
        for(auto & modelo : modelos_linha)
        {
            std::cout << modelo->getName() << "    " << modelo->getID() << "\n";
        }
    }
}

void Ui::menuAdicionarModelo() {
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
        std::cout << "Erro: Linha inválida.\n";
        return;
    }

    std::cout << "\nDigite o nome do novo modelo que deseja criar: ";
    limparInput();
    std::getline(std::cin, name);

    if(name.find(type) != std::string::npos)
    {
        catalog.addNewModel(name);
        std::cout << "Modelo adicionado com sucesso!\n";
    }else{
        std::cout << "Escreva um Modelo que pertence a linha.\n";
    }
}

void Ui::menuRemoverModelo() {
    listarModelosComId();
    int id;
    std::cout << "\nID para remover: ";
    if (std::cin >> id) {
        catalog.removeModel(id);
    } else {
        std::cout << "\nDigite um ID correto.";
        limparInput();
    }
}

void Ui::menuLeituraFases() {
    listarModelosComId();
    int id;
    
    std::cout << "ID do medidor que deseja realizar as leituras: ";
    if (!(std::cin >> id))
    { 
        limparInput(); 
        return; 
    }
    
    auto measurements = catalog.getMeasurementsPhases(id);
    for(int cont = 0; cont < measurements.size(); cont++)
    {
        std::cout << "A leitura da " << cont + 1 << "° fase é : " << measurements[cont ] << "\n";
    }
}

// --- Menus de Texto ---

void Ui::exibir_menu_inicial() {
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

void Ui::exibir_menu_linhas() {
    std::cout << "\n--- Digite o nome de uma das linhas abaixo ---\n";
    for (const auto & linha : catalog.getLines()) 
    {
        std::cout << "  [" << linha << "]";
    }
    std::cout << "\nLinha: ";
}