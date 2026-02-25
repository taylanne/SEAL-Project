/**
 * @file ScheduleManager.cpp
 * @brief Implementação das regras de negócio das Escalas.
 */

#include "ScheduleManager.h"

bool ScheduleManager::AdicionarEscala(const std::string& comodo, const std::string& morador, const std::string& periodo) {
    // Regra de Negócio: Bloqueia duplicidade exata (mesmo morador, mesmo cômodo, mesmo período)
    for (const auto& escala : listaEscalas) {
        if (escala.nomeComodo == comodo && 
            escala.telegramMorador == morador && 
            escala.periodo == periodo) {
            return false; 
        }
    }

    ScheduleData novaEscala;
    novaEscala.nomeComodo = comodo;
    novaEscala.telegramMorador = morador;
    novaEscala.periodo = periodo;

    listaEscalas.push_back(novaEscala);
    return true;
}

std::vector<ScheduleData> ScheduleManager::ListarEscalas() {
    return listaEscalas;
}

// --- Funções da Fábrica (Factory) ---

IScheduleManager* CreateScheduleManager() {
    return new ScheduleManager();
}

void DeleteScheduleManager(IScheduleManager* manager) {
    delete manager;
}