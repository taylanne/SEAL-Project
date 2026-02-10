/**
 * @file UserManager.cpp
 * @brief Implementação concreta da lógica de gerenciamento de usuários.
 * @details Este arquivo contém a classe oculta UserManager e as funções de fábrica.
 * A implementação utiliza um std::vector para armazenamento volátil (RAM).
 * @author Seu Nome
 * @date 2025
 */

#include "IUserManager.h"
#include <iostream>
#include <algorithm> // Necessário para remove_if

/**
 * @class UserManager
 * @brief Implementação concreta da interface IUserManager.
 * * Esta classe é responsável por manter o estado da lista de usuários
 * durante a execução do programa. Ela não é exposta diretamente no header,
 * garantindo o encapsulamento (Pattern Pimpl/Interface).
 */
class UserManager : public IUserManager {
private:
    /**
     * @brief Lista dinâmica para armazenar os usuários.
     * @details Utiliza std::vector para armazenamento sequencial em memória.
     * Os dados são perdidos quando o programa é fechado.
     */
    std::vector<UserData> listaUsuarios;

public:
    /**
     * @brief Implementação da adição de usuário com verificação de unicidade.
     * @details Realiza uma busca linear O(N) para garantir que o TelegramID não existe
     * antes de inserir.
     * * @param nome Nome do morador.
     * @param telegram ID único.
     * @param data Data de registro.
     * @return true se inserido, false se duplicado.
     */
    bool AdicionarUsuario(const std::string& nome, const std::string& telegram, const std::string& data) override {
        // Verifica duplicidade percorrendo a lista
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

    /**
     * @brief Remove um usuário utilizando o idioma Erase-Remove.
     * @details Utiliza std::remove_if para reordenar o vetor e vector::erase 
     * para remover os elementos excedentes. Complexidade O(N).
     * * @param telegramID A chave de busca para remoção.
     * @return true se encontrou e removeu, false caso contrário.
     */
    bool RemoverUsuario(const std::string& telegramID) override {
        // Passo 1: remove_if move os elementos não deletados para o início
        auto it = std::remove_if(listaUsuarios.begin(), listaUsuarios.end(),
            [&](const UserData& u) {
                return u.telegramID == telegramID;
            });

        // Passo 2: Verifica se o iterador retornado não é o fim do vetor
        if (it != listaUsuarios.end()) {
            // Passo 3: Apaga os elementos "sobra" do final do vetor
            listaUsuarios.erase(it, listaUsuarios.end()); 
            std::cout << "[LIB] Usuario com ID " << telegramID << " removido." << std::endl;
            return true;
        }

        std::cout << "[ERRO] ID " << telegramID << " nao encontrado para remocao." << std::endl;
        return false;
    }

    /**
     * @brief Retorna uma cópia da lista atual.
     * @return std::vector<UserData> contendo todos os registros.
     */
    std::vector<UserData> ListarUsuarios() override {
        return listaUsuarios;
    }
};

// --- Funções da Fábrica (Factory Pattern) ---

/**
 * @brief Aloca uma nova instância de UserManager na memória Heap.
 * @return Ponteiro para a interface genérica.
 */
IUserManager* CreateManager() {
    return new UserManager();
}

/**
 * @brief Libera a memória alocada para o gerenciador.
 * @param manager Ponteiro para a instância a ser deletada.
 */
void DeleteManager(IUserManager* manager) {
    delete manager;
}