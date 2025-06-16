#include "cliente.h"
#include <iostream>

ClienteJuridico::ClienteJuridico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cnpj)
    : Cliente(codigo, nome, endereco), cnpj(cnpj) {}

void ClienteJuridico::mostrarDados() const {
    std::cout << "--- Cliente Juridico ---" << std::endl;
    std::cout << "Codigo: " << codigo << " | Nome: " << nome << " | CNPJ: " << cnpj << std::endl;
    endereco.mostrarEndereco();
}

double ClienteJuridico::getTaxaDesconto() const {
    return 0.20;
}
