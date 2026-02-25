/**
 * @file ScheduleManager.h
 * @brief Declaração da classe concreta de gerenciamento de Escalas.
 */

#pragma once
#include "IScheduleManager.h"
#include <vector>

class ScheduleManager : public IScheduleManager {
private:
    std::vector<ScheduleData> listaEscalas;

public:
    bool AdicionarEscala(const std::string& comodo, const std::string& morador, const std::string& periodo) override;
    std::vector<ScheduleData> ListarEscalas() override;
};