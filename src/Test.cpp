#include <iostream>
#include <cassert>
#include <vector>
#include "IUserManager.h"

// Função auxiliar para logs
void Log(const std::string& msg) {
    std::cout << "\033[1;33m[CENARIO] " << msg << "\033[0m" << std::endl;
}

void TestarCenarioAugusto(IUserManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("DADO QUE o administrador esteja na tela de Gerenciar Moradores (Sistema Inicializado)");
    
    // Verificação inicial: lista deve estar vazia
    assert(manager->ListarUsuarios().empty() == true);


    Log("QUANDO insira o nome 'Augusto', ID '@augusto' e data '15/01/2025'");
    Log("E o administrador clicar no botão de Cadastrar");
    
    bool resultado = manager->AdicionarUsuario("Augusto", "@augusto", "15/01/2025");


    Log("ENTÃO o cadastro deve ser realizado com sucesso");
    assert(resultado == true);


    Log("E os dados (Augusto, @augusto, 15/01/2025) devem estar na lista de gerenciamento");
    std::vector<UserData> lista = manager->ListarUsuarios();
    
    assert(lista.size() == 1);
    assert(lista[0].nome == "Augusto");
    assert(lista[0].telegramID == "@augusto");
    assert(lista[0].dataCadastro == "15/01/2025");
    
    std::cout << "\033[1;32m>>> PASSO 1: Cadastro do Augusto verificado com sucesso. <<<\033[0m" << std::endl;
}

void TestarBloqueioDuplicidade(IUserManager* manager) {
    std::cout << "\n---------------------------------------------------" << std::endl;
    Log("CENARIO EXTRA: Tentativa de ID duplicado");
    Log("QUANDO tento cadastrar outro usuario com o MESMO ID '@augusto'");
    
    // Tentamos cadastrar um impostor com o mesmo ID
    bool resultado = manager->AdicionarUsuario("Impostor", "@augusto", "20/02/2025");

    Log("ENTÃO o sistema NÃO deve permitir o cadastro (retornar false)");
    assert(resultado == false);

    Log("E a lista deve continuar contendo apenas 1 registro (o Augusto original)");
    std::vector<UserData> lista = manager->ListarUsuarios();
    assert(lista.size() == 1);
    assert(lista[0].nome == "Augusto"); // Garante que não sobrescreveu

    std::cout << "\033[1;32m>>> PASSO 2: Bloqueio de duplicidade verificado com sucesso. <<<\033[0m" << std::endl;
}

int main() {
    // Setup
    IUserManager* manager = CreateManager();

    // Execução dos Cenários
    TestarCenarioAugusto(manager);
    TestarBloqueioDuplicidade(manager);

    // Teardown
    DeleteManager(manager);

    std::cout << "\n\033[1;34mRESULTADO FINAL: Todos os requisitos do BDD foram atendidos!\033[0m" << std::endl;
    return 0;
}