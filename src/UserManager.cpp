/**
 * @file UserManager.cpp
 * @brief Implementação da lógica.
 */

#include "UserManager.h" // Inclui o header da classe concreta
#include <iostream>
#include <algorithm>

// --- Implementação dos Métodos da Classe ---

bool UserManager::AdicionarUsuario(const std::string& nome, const std::string& telegram, const std::string& data) {
    // Verifica duplicidade
    for (const auto& usuario : listaUsuarios) {
        if (usuario.telegramID == telegram) {
            return false; 
        }
    }

    UserData novoUsuario;
    novoUsuario.nome = nome;
    novoUsuario.telegramID = telegram;
    novoUsuario.dataCadastro = data;

    listaUsuarios.push_back(novoUsuario);
    return true;
}

bool UserManager::RemoverUsuario(const std::string& telegramID) {
    auto it = std::remove_if(listaUsuarios.begin(), listaUsuarios.end(),
        [&](const UserData& u) {
            return u.telegramID == telegramID;
        });

    if (it != listaUsuarios.end()) {
        listaUsuarios.erase(it, listaUsuarios.end()); 
        std::cout << "[LIB] Usuario removido: " << telegramID << std::endl;
        return true;
    }
    return false;
}

std::vector<UserData> UserManager::ListarUsuarios() {
    return listaUsuarios;
}

// --- Funções da Fábrica (Factory) ---
// Elas precisam criar o 'new UserManager', então precisam conhecer a classe concreta.

IUserManager* CreateManager() {
    return new UserManager();
}

void DeleteManager(IUserManager* manager) {
    delete manager;
}