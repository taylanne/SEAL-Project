#include <iostream>
#include <cassert>
#include <vector>
#include "IScheduleManager.h"

// Função auxiliar para logs com cor diferente (Magenta)
void Log(const std::string& msg) {
    std::cout << "\033[1;35m[CENARIO ESCALA] " << msg << "\033[0m" << std::endl;
}

void TestarCenarioAdicionarEscala(IScheduleManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("DADO QUE o administrador esteja no modulo de Gerenciar Escalas");
    
    // Verificação inicial: lista deve estar vazia
    assert(manager->ListarEscalas().empty() == true);

    Log("QUANDO insira o Comodo 'Cozinha', Morador '@augusto' e Periodo 'Segunda'");
    Log("E o administrador clicar em Gerar Escala");
    
    bool resultado = manager->AdicionarEscala("Cozinha", "@augusto", "Segunda");

    Log("ENTAO o cadastro deve ser realizado com sucesso");
    assert(resultado == true);

    Log("E os dados exatos devem estar na lista de escalas");
    std::vector<ScheduleData> lista = manager->ListarEscalas();
    
    assert(lista.size() == 1);
    assert(lista[0].nomeComodo == "Cozinha");
    assert(lista[0].telegramMorador == "@augusto");
    assert(lista[0].periodo == "Segunda");
    
    std::cout << "\033[1;32m>>> PASSO 1: Cadastro de Escala verificado com sucesso. <<<\033[0m" << std::endl;
}

void TestarBloqueioDuplicidadeEscala(IScheduleManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("CENARIO EXTRA: Tentativa de Escala Duplicada");
    Log("QUANDO tento cadastrar a EXATA MESMA ESCALA (Cozinha, @augusto, Segunda)");
    
    // Tentamos cadastrar a mesma escala novamente
    bool resultado = manager->AdicionarEscala("Cozinha", "@augusto", "Segunda");

    Log("ENTAO o sistema NAO deve permitir o cadastro (retornar false)");
    assert(resultado == false);

    Log("E a lista deve continuar contendo apenas 1 registro");
    std::vector<ScheduleData> lista = manager->ListarEscalas();
    assert(lista.size() == 1);

    std::cout << "\033[1;32m>>> PASSO 2: Bloqueio de duplicidade de Escala verificado com sucesso. <<<\033[0m" << std::endl;
}

int main() {
    // Setup
    IScheduleManager* manager = CreateScheduleManager();

    // Execução dos Cenários
    TestarCenarioAdicionarEscala(manager);
    TestarBloqueioDuplicidadeEscala(manager);

    // Teardown
    DeleteScheduleManager(manager);

    std::cout << "\n\033[1;34mRESULTADO FINAL: Todos os requisitos do BDD de Escalas foram atendidos!\033[0m\n" << std::endl;
    return 0;
}