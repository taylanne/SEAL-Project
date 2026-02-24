/**
 * @file IRoomManager.h
 * @brief Interface para o módulo de gerenciamento de cômodos.
 * @details Define o contrato e as estruturas de dados para manipular
 * os ambientes (cômodos) do sistema.
 * @author Seu Nome
 * @date 2026
 */

#pragma once
#include <string>
#include <vector>

// Configuração de exportação/importação para Componentização (DLL/SO)
#if defined(_WIN32) || defined(_WIN64)
    #ifdef ROOMDLL_EXPORTS
        #define ROOM_API __declspec(dllexport)
    #else
        #define ROOM_API __declspec(dllimport)
    #endif
#else
    #define ROOM_API __attribute__((visibility("default")))
#endif

/**
 * @struct RoomData
 * @brief Estrutura de Transferência de Dados (DTO) para Cômodos.
 */
struct RoomData {
    std::string nome;      ///< Nome identificador do cômodo (ex: "Sala de Reuniões")
    std::string descricao; ///< Descrição detalhada do ambiente e seus recursos
};

/**
 * @class IRoomManager
 * @brief Interface abstrata para manipulação de cômodos.
 */
class IRoomManager {
public:
    virtual ~IRoomManager() {}

    /**
     * @brief Adiciona um novo cômodo à lista de gerenciamento.
     * @param nome Nome do cômodo (deve ser único).
     * @param descricao Detalhes sobre o cômodo.
     * @return true se o cômodo foi cadastrado com sucesso.
     * @return false se já existir um cômodo com o mesmo nome.
     */
    virtual bool AdicionarComodo(const std::string& nome, const std::string& descricao) = 0;

    /**
     * @brief Retorna a lista de todos os cômodos cadastrados.
     * @return std::vector<RoomData> contendo os registros.
     */
    virtual std::vector<RoomData> ListarComodos() = 0;
};

// --- Funções da Fábrica (Factory Pattern) ---
extern "C" {
    /**
     * @brief Cria uma nova instância concreta do gerenciador de cômodos.
     * @return Ponteiro para a interface IRoomManager.
     */
    ROOM_API IRoomManager* CreateRoomManager();

    /**
     * @brief Libera a memória da instância do gerenciador.
     * @param manager Ponteiro para a instância a ser destruída.
     */
    ROOM_API void DeleteRoomManager(IRoomManager* manager);
}