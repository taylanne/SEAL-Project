#include <iostream>
#include <limits>
#include "IUserManager.h"

void LimparBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    IUserManager* gerenciador = CreateManager();
    int opcao = 0;
    
    do {
        std::cout << "\n--- GESTAO DE MORADORES ---\n";
        std::cout << "1. Cadastrar Usuario\n";
        std::cout << "2. Listar Usuarios\n";
        std::cout << "3. Remover Usuario\n"; // Nova opção
        std::cout << "0. Sair\n";
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
            auto usuarios = gerenciador->ListarUsuarios();
            std::cout << "\n--- LISTA ---\n";
            for (const auto& u : usuarios) {
                std::cout << u.nome << " (" << u.telegramID << ") - " << u.dataCadastro << std::endl;
            }
        }
        else if (opcao == 3) {
            std::string telegram;
            std::cout << "Informe o ID Telegram para remover: ";
            std::getline(std::cin, telegram);

            if (gerenciador->RemoverUsuario(telegram)) {
                std::cout << ">>> Usuario removido com sucesso!\n";
            } else {
                std::cout << ">>> Usuario nao encontrado.\n";
            }
        }

    } while (opcao != 0);

    DeleteManager(gerenciador);
    return 0;
}