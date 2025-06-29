//ENDERECO.H
#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include <iostream>

class Endereco {
private:
    std::string rua;
    int numero;
    std::string bairro;
    std::string cidade;

public:
    Endereco(const std::string& r = "", int n = 0, const std::string& b = "", const std::string& c = "");

    void mostrarEndereco() const;
};

#endif