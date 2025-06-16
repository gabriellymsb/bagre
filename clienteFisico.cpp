//CLIENTEFISICO.H
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

// --- Implementação ClienteFisico ---
ClienteFisico::ClienteFisico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cpf)
    : Cliente(codigo, nome, endereco), cpf(cpf) {}

void ClienteFisico::mostrarDados() const {
    std::cout << "--- Cliente Fisico ---" << std::endl;
    std::cout << "Codigo: " << codigo << " | Nome: " << nome << " | CPF: " << cpf << std::endl;
    endereco.mostrarEndereco();
}

// Regra de negócio: Cliente físico tem 10% de desconto.
double ClienteFisico::getTaxaDesconto() const {
    return 0.10; 
}

