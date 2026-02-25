/**
 * @file IScheduleManager.h
 * @brief Interface abstrata para o gerenciamento de Escalas de limpeza/uso.
 * @details Define as operações para associar um Morador, um Cômodo e um Período.
 * @author Seu Nome
 * @date 2026
 */

#pragma once
#include <string>
#include <vector>

// Configuração para Componentização (Evita o erro de dllimport no Qt Windows)
#if defined(_WIN32) || defined(_WIN64)
    #define SCHEDULE_API 
#else
    #define SCHEDULE_API __attribute__((visibility("default")))
#endif

/**
 * @struct ScheduleData
 * @brief Estrutura de Transferência de Dados (DTO) para Escalas.
 */
struct ScheduleData {
    std::string nomeComodo;      ///< Nome do cômodo associado
    std::string telegramMorador; ///< ID do Telegram do morador responsável
    std::string periodo;         ///< Período de responsabilidade (ex: "Segunda", "01/03 a 07/03")
};

/**
 * @class IScheduleManager
 * @brief Interface para manipulação de escalas.
 */
class IScheduleManager {
public:
    virtual ~IScheduleManager() {}

    /**
     * @brief Adiciona uma nova escala no sistema.
     * @param comodo O nome do cômodo.
     * @param morador O ID do morador.
     * @param periodo O período definido.
     * @return true se cadastrado com sucesso, false se a exata escala já existir.
     */
    virtual bool AdicionarEscala(const std::string& comodo, const std::string& morador, const std::string& periodo) = 0;

    /**
     * @brief Lista todas as escalas cadastradas.
     * @return std::vector<ScheduleData> com as escalas.
     */
    virtual std::vector<ScheduleData> ListarEscalas() = 0;
};

// --- Funções da Fábrica (Factory Pattern) ---
extern "C" {
    SCHEDULE_API IScheduleManager* CreateScheduleManager();
    SCHEDULE_API void DeleteScheduleManager(IScheduleManager* manager);
}