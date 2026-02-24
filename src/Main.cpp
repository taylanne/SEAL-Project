#include <iostream>
#include <limits>
#include "IUserManager.h"
#include "IRoomManager.h"

void LimparBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// --- SUBMENU DE MORADORES ---
void MenuMoradores(IUserManager* gerenciador) {
    int opcao = 0;
    do {
        std::cout << "\n--- GESTAO DE MORADORES ---\n";
        std::cout << "1. Cadastrar Morador\n";
        std::cout << "2. Listar Moradores\n";
        std::cout << "0. Voltar\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;
        LimparBuffer();

        if (opcao == 1) {
            std::string nome, telegram, data;
            std::cout << "Nome: "; std::getline(std::cin, nome);
            std::cout << "ID Telegram: "; std::getline(std::cin, telegram);
            std::cout << "Data: "; std::getline(std::cin, data);

            if(gerenciador->AdicionarUsuario(nome, telegram, data))
                std::cout << ">>> Sucesso!\n";
            else
                std::cout << ">>> Erro: ID ja existe.\n";
        }
        else if (opcao == 2) {
            auto lista = gerenciador->ListarUsuarios();
            std::cout << "\n--- LISTA DE MORADORES ---\n";
            for (const auto& u : lista) {
                std::cout << "- " << u.nome << " (" << u.telegramID << ") cadastrado em " << u.dataCadastro << "\n";
            }
        }
    } while (opcao != 0);
}

// --- SUBMENU DE COMODOS ---
void MenuComodos(IRoomManager* gerenciador) {
    int opcao = 0;
    do {
        std::cout << "\n--- GESTAO DE COMODOS ---\n";
        std::cout << "1. Cadastrar Comodo\n";
        std::cout << "2. Listar Comodos\n";
        std::cout << "0. Voltar\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;
        LimparBuffer();

        if (opcao == 1) {
            std::string nome, descricao;
            std::cout << "Nome do Comodo (ex: Sala de Reuniao): "; std::getline(std::cin, nome);
            std::cout << "Descricao: "; std::getline(std::cin, descricao);

            if(gerenciador->AdicionarComodo(nome, descricao))
                std::cout << ">>> Sucesso!\n";
            else
                std::cout << ">>> Erro: Comodo ja existe.\n";
        }
        else if (opcao == 2) {
            auto lista = gerenciador->ListarComodos();
            std::cout << "\n--- LISTA DE COMODOS ---\n";
            for (const auto& c : lista) {
                std::cout << "- [" << c.nome << "] Descricao: " << c.descricao << "\n";
            }
        }
    } while (opcao != 0);
}

// --- MENU PRINCIPAL ---
int main() {
    // Inicializa as duas DLLs/Bibliotecas
    IUserManager* gerenciadorUsuarios = CreateManager();
    IRoomManager* gerenciadorComodos = CreateRoomManager();
    
    int opcao = 0;
    do {
        std::cout << "\n====== SISTEMA SEAL ======\n";
        std::cout << "1. Menu de Moradores\n";
        std::cout << "2. Menu de Comodos\n";
        std::cout << "0. Sair do Sistema\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            MenuMoradores(gerenciadorUsuarios);
        } else if (opcao == 2) {
            MenuComodos(gerenciadorComodos);
        }
        
    } while (opcao != 0);

    // Limpa a memória das duas bibliotecas ao sair
    DeleteManager(gerenciadorUsuarios);
    DeleteRoomManager(gerenciadorComodos);
    
    return 0;
}