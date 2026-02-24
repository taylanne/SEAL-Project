#include <iostream>
#include <cassert>
#include <vector>
#include "IRoomManager.h"

// Função auxiliar para logs com cor diferente (Ciano)
void Log(const std::string& msg) {
    std::cout << "\033[1;36m[CENARIO COMODO] " << msg << "\033[0m" << std::endl;
}

void TestarCenarioAdicionarComodo(IRoomManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("DADO QUE o administrador esteja no modulo de Gerenciar Comodos (Sistema Inicializado)");
    
    // Verificação inicial: lista deve estar vazia
    assert(manager->ListarComodos().empty() == true);

    Log("QUANDO insira o nome 'Sala de Reunioes' e a descricao 'Mesa grande e projetor'");
    Log("E o administrador clicar no botao de Cadastrar");
    
    bool resultado = manager->AdicionarComodo("Sala de Reunioes", "Mesa grande e projetor");

    Log("ENTAO o cadastro deve ser realizado com sucesso");
    assert(resultado == true);

    Log("E os dados (Sala de Reunioes, Mesa grande e projetor) devem estar na lista");
    std::vector<RoomData> lista = manager->ListarComodos();
    
    assert(lista.size() == 1);
    assert(lista[0].nome == "Sala de Reunioes");
    assert(lista[0].descricao == "Mesa grande e projetor");
    
    std::cout << "\033[1;32m>>> PASSO 1: Cadastro de Comodo verificado com sucesso. <<<\033[0m" << std::endl;
}

void TestarBloqueioDuplicidadeComodo(IRoomManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("CENARIO EXTRA: Tentativa de nome duplicado");
    Log("QUANDO tento cadastrar outro comodo com o MESMO NOME 'Sala de Reunioes'");
    
    // Tentamos cadastrar outro cômodo, mas com o mesmo nome (regra não permite)
    bool resultado = manager->AdicionarComodo("Sala de Reunioes", "Outra sala qualquer");

    Log("ENTAO o sistema NAO deve permitir o cadastro (retornar false)");
    assert(resultado == false);

    Log("E a lista deve continuar contendo apenas 1 registro (a Sala original)");
    std::vector<RoomData> lista = manager->ListarComodos();
    assert(lista.size() == 1);
    assert(lista[0].nome == "Sala de Reunioes"); // Garante que não sobrescreveu
    assert(lista[0].descricao == "Mesa grande e projetor"); // Garante que manteve a descrição certa

    std::cout << "\033[1;32m>>> PASSO 2: Bloqueio de duplicidade verificado com sucesso. <<<\033[0m" << std::endl;
}

int main() {
    // Setup
    IRoomManager* manager = CreateRoomManager();

    // Execução dos Cenários
    TestarCenarioAdicionarComodo(manager);
    TestarBloqueioDuplicidadeComodo(manager);

    // Teardown
    DeleteRoomManager(manager);

    std::cout << "\n\033[1;34mRESULTADO FINAL: Todos os requisitos do BDD de Comodos foram atendidos!\033[0m" << std::endl;
    return 0;
}