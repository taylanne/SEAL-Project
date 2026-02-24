/**
 * @file IUserManager.h
 * @brief Interface (Contrato) que o mundo externo enxerga.
 */

#pragma once
#include <string>
#include <vector>

// Configuração de exportação DLL/SO
#if defined(_WIN32) || defined(_WIN64)
    #ifdef USERDLL_EXPORTS
        #define USER_API __declspec(dllexport)
    #else
        #define USER_API __declspec(dllimport)
    #endif
#else
    #define USER_API __attribute__((visibility("default")))
#endif

struct UserData {
    std::string nome;
    std::string telegramID;
    std::string dataCadastro;
};

class IUserManager {
public:
    virtual ~IUserManager() {}
    virtual bool AdicionarUsuario(const std::string& nome, const std::string& telegram, const std::string& data) = 0;
    virtual bool RemoverUsuario(const std::string& telegramID) = 0;
    virtual std::vector<UserData> ListarUsuarios() = 0;
};

// Fábrica
extern "C" {
    USER_API IUserManager* CreateManager();
    USER_API void DeleteManager(IUserManager* manager);
}