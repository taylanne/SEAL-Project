/**
 * @file RoomManager.cpp
 * @brief Implementação dos métodos e regras de negócio de cômodos.
 */

#include "RoomManager.h"
#include <iostream>

// --- Implementação dos Métodos da Classe ---

bool RoomManager::AdicionarComodo(const std::string& nome, const std::string& descricao) {
    // Regra de Negócio: Evitar cômodos com o mesmo nome
    for (const auto& comodo : listaComodos) {
        if (comodo.nome == nome) {
            std::cerr << "[ERRO] Comodo com nome '" << nome << "' ja existe!" << std::endl;
            return false; 
        }
    }

    RoomData novoComodo;
    novoComodo.nome = nome;
    novoComodo.descricao = descricao;

    listaComodos.push_back(novoComodo);
    return true;
}

std::vector<RoomData> RoomManager::ListarComodos() {
    return listaComodos;
}

// --- Funções da Fábrica (Factory) ---

IRoomManager* CreateRoomManager() {
    return new RoomManager();
}

void DeleteRoomManager(IRoomManager* manager) {
    delete manager;
}