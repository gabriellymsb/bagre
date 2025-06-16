// CLIENTE.H
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "endereco.h"

// --- Classe base abstrata Cliente ---
class Cliente {
protected: // CORREÇÃO: protected para que as classes filhas possam acessar
    int codigo;
    std::string nome;
    Endereco endereco;

public:
    Cliente(int codigo, const std::string& nome, const Endereco& endereco);
    virtual ~Cliente() = default; // Boa prática usar default

    int getCodigo() const;
    std::string getNome() const;

    // Métodos virtuais puros (abstratos)
    virtual void mostrarDados() const = 0;
    virtual double getTaxaDesconto() const = 0;
};

// --- Classe derivada ClienteFisico ---
class ClienteFisico final : public Cliente { // Adicionado 'final'
private:
    std::string cpf;

public:
    ClienteFisico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cpf);
    
    void mostrarDados() const override;
    double getTaxaDesconto() const override;
};

// --- Classe derivada ClienteJuridico ---
class ClienteJuridico final : public Cliente { // Adicionado 'final'
private:
    std::string cnpj;

public:
    ClienteJuridico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cnpj);

    void mostrarDados() const override;
    double getTaxaDesconto() const override;
};

#endif