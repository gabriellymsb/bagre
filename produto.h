// PRODUTO.H
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

enum class Categoria {
    ALIMENTO,
    BEBIDA,
    ELETRONICO,
    VESTUARIO,
    LIVRO,
    LIMPEZA
};

class Produto {
private:
    int codigo;
    std::string nome;
    double preco;
    Categoria categoria;

public:
    Produto(int codigo, const std::string& nome, double preco, Categoria categoria);

    int getCodigo() const;
    std::string getNome() const;
    double getPreco() const;
    
    std::string categoriaToString() const;
};

#endif