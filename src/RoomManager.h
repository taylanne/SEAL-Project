/**
 * @file RoomManager.h
 * @brief Declaração da classe concreta de gerenciamento de cômodos.
 * @details Esta classe implementa a interface IRoomManager. Ela fica oculta
 * do cliente final para garantir a separação de camadas.
 */

#pragma once
#include "IRoomManager.h"
#include <vector>

/**
 * @class RoomManager
 * @brief Implementação concreta em memória para a gestão de cômodos.
 */
class RoomManager : public IRoomManager {
private:
    /**
     * @brief Lista sequencial armazenando os dados dos cômodos na RAM.
     */
    std::vector<RoomData> listaComodos;

public:
    // Sobrescrita dos métodos da interface
    bool AdicionarComodo(const std::string& nome, const std::string& descricao) override;
    std::vector<RoomData> ListarComodos() override;
};