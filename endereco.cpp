//ENDERECO.CPP
#include "endereco.h"

Endereco::Endereco(std::string& r, int n, const std::string& b, const std::string& c)
    : rua(r), numero(n), bairro(b), cidade(c) {}

void Endereco::mostrarEndereco() const {
    std::cout << "Endereco: Rua " << rua << ", " << numero << " - Bairro: " << bairro << " - Cidade: " << cidade << std::endl;
}