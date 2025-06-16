#include "cliente.h"
#include <iostream>

ClienteFisico::ClienteFisico(int codigo, const std::string& nome, const Endereco& endereco, const std::string& cpf)
    : Cliente(codigo, nome, endereco), cpf(cpf) {}

void ClienteFisico::mostrarDados() const {
    std::cout << "--- Cliente Fisico ---" << std::endl;
    std::cout << "Codigo: " << codigo << " | Nome: " << nome << " | CPF: " << cpf << std::endl;
    endereco.mostrarEndereco();
}

double ClienteFisico::getTaxaDesconto() const {
    return 0.10;
}
