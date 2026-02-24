/**
 * @file UserManager.h
 * @brief Declaração da classe concreta.
 * @details Aqui definimos os métodos e variáveis privadas, mas não a lógica.
 */

#pragma once
#include "IUserManager.h" // Precisa conhecer a interface para herdar
#include <vector>

// Herdamos de IUserManager
class UserManager : public IUserManager {
private:
    std::vector<UserData> listaUsuarios; // Onde os dados ficam guardados

public:
    // Declaração dos métodos (Note o 'override')
    bool AdicionarUsuario(const std::string& nome, const std::string& telegram, const std::string& data) override;
    
    bool RemoverUsuario(const std::string& telegramID) override;
    
    std::vector<UserData> ListarUsuarios() override;
};