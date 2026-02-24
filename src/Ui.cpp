#include "Ui.h"
#include <string>
#include <iostream>
#include <functional>

Ui::Ui()
    : catalogo()
{    
}
/*
    Falta:
    -7. Adicionar um novo modelo a uma linha específica
    -8. Remover o modelo informando o seu id
    - Adicionar aos medidores leitura de Tensão e Corrente, caso aquele medidor seja monofásico,
      não pode ter o mesmo comportamento que o o bifásico e o trifásico;
      mono -
      bi -
      tri -
*/
void Ui::run ()
{
    bool executando = true;
    while(executando)
    {   
        int op;
        exibir_menu_inicial();
        std::cin >> op;

        switch (op)
        {
            case 1:
            {
                std::string nome;
                exibir_menu_linhas();
                std::cin >> nome;
                
                bool exists = false; 
                std::cout << "\n==============================\n";
                std::cout << "Modelos da Linha " << nome;
                std::cout << "\n==============================\n";
                for (auto & nome_modelo : catalogo.getListModels().getList())
                {
                    if(nome_modelo.type == nome)
                    {
                        std::cout << nome_modelo.meter->getNameMeter() << "\n";
                        exists = true;
                    }
                }
                if(!exists){
                    std::cout << "Não existem modelos nessa linha" << "\n";
                }
                break;
            }
            case 2:
            {
                std::cout << "\n==============================\n";
                std::cout << "Linhas existentes " ;
                std::cout << "\n==============================\n";
                for (auto nome_linhas : catalogo.getLines())
                {
                    std::cout << nome_linhas << "\n";
                }
                break;
            }

            case 3:
            {
                for( auto linha : catalogo.getLines())
                {
                    std::cout << "\n==============================\n";
                    std::cout << "Modelos da Linha " <<linha;
                    std::cout << "\n==============================\n";
                    for (auto & nome_modelo : catalogo.getListModels().getList())
                    {
                        if(nome_modelo.type == linha){
                            std::cout << nome_modelo.meter->getNameMeter() << "\n";
                        }
                    }
                }
                break;
            }
            
            case 4:
            {
                executando = false;
                break;
            }
            
            default:
            {
                if (std::cin.fail() || op != 1 || op != 2 || op != 3 || op != 4 )
                {
                    std::cout << "Digite uma opção válida.\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
        }
    }
}


void Ui::exibir_menu_inicial()
{
    std::cout << "\n==============================\n";
    std::cout << "Menu Principal " ;
    std::cout << "\n==============================";

    std::cout <<"\n(1) Exibir Menu de Seleção de Linhas disponíveis;"
              <<"\n(2) Exibir todas as linhas disponíveis;"
              <<"\n(3) Exibir todos modelos de Medidores de Energia;"
              <<"\n(4) Sair da Aplicação.\n";
}


void Ui::exibir_menu_linhas()
{
    std::cout << "\n==============================\n";
    std::cout << "Menu Linhas " ;
    std::cout << "\n==============================\n";

    std::cout << "Digite a opção de linha que deseja exibir:\n";
    for (auto linha : catalogo.getLines())
    {
        std::cout << linha << "\n";
    }
}