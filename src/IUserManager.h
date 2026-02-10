/**
 * @file IUserManager.h
 * @brief Interface para o sistema de gerenciamento de usuários.
 * @author Seu Nome
 * @date 2025
 */

#pragma once
#include <string>
#include <vector>

// Configuração de visibilidade para Linux/Windows
#if defined(_WIN32) || defined(_WIN64)
    #ifdef USERDLL_EXPORTS
        #define USER_API __declspec(dllexport)
    #else
        #define USER_API __declspec(dllimport)
    #endif
#else
    #define USER_API __attribute__((visibility("default")))
#endif

/**
 * @struct UserData
 * @brief Estrutura simples para transportar dados do usuário (DTO).
 */
struct UserData {
    std::string nome;           ///< Nome completo do morador
    std::string telegramID;     ///< ID único do Telegram (ex: @augusto)
    std::string dataCadastro;   ///< Data de entrada no formato DD/MM/AAAA
};

/**
 * @class IUserManager
 * @brief Interface abstrata para manipulação de usuários.
 * * Define o contrato que qualquer implementação de gerenciador
 * deve seguir. Utiliza o padrão Factory para instanciação.
 */
class IUserManager {
public:
    virtual ~IUserManager() {}
    
    /**
     * @brief Adiciona um novo usuário ao sistema.
     * * @param nome Nome completo do morador.
     * @param telegram ID do Telegram (deve ser único).
     * @param data Data de cadastro.
     * @return true Se cadastrado com sucesso.
     * @return false Se o ID já existir na lista.
     */
    virtual bool AdicionarUsuario(const std::string& nome, const std::string& telegram, const std::string& data) = 0;
    
    /**
     * @brief Remove um usuário pelo ID.
     * * @param telegramID O ID do usuário a ser removido.
     * @return true Se o usuário foi encontrado e removido.
     * @return false Se o usuário não existe.
     */
    virtual bool RemoverUsuario(const std::string& telegramID) = 0;

    /**
     * @brief Lista todos os usuários cadastrados.
     * @return Um vetor contendo estruturas UserData.
     */
    virtual std::vector<UserData> ListarUsuarios() = 0;
};

extern "C" {
    /**
     * @brief Cria uma instância do Gerenciador.
     * @return Ponteiro para a interface IUserManager.
     */
    USER_API IUserManager* CreateManager();

    /**
     * @brief Destrói a instância e libera memória.
     * @param manager Ponteiro para o gerenciador a ser destruído.
     */
    USER_API void DeleteManager(IUserManager* manager);
}