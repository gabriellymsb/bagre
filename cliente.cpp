#include "cliente.h"

Cliente::Cliente(int codigo, const std::string& nome, const Endereco& endereco)
    : codigo(codigo), nome(nome), endereco(endereco) {}

int Cliente::getCodigo() const {
    return codigo;
}

std::string Cliente::getNome() const {
    return nome;
}
