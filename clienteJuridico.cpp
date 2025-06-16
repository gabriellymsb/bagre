// clienteJURIDICO.H
#include "cliente.h"
#include <iostream>

// --- Implementação Cliente (Base) ---
Cliente::Cliente(int codigo, const std::string& nome, const Endereco& endereco)
    : codigo(codigo), nome(nome), endereco(endereco) {}

int Cliente::getCodigo() const {
    return codigo;
}

std::string Cliente::getNome() const {
    return nome;
}
// --- Implementação ClienteJuridico ---
ClienteJuridico::ClienteJuridico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cnpj)
    : Cliente(codigo, nome, endereco), cnpj(cnpj) {}

void ClienteJuridico::mostrarDados() const {
    std::cout << "--- Cliente Juridico ---" << std::endl;
    std::cout << "Codigo: " << codigo << " | Nome: " << nome << " | CNPJ: " << cnpj << std::endl;
    endereco.mostrarEndereco();
}

// Regra de negócio: Cliente jurídico tem 20% de desconto.
double ClienteJuridico::getTaxaDesconto() const {
    return 0.20;
}