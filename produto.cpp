// PRODUTO.CPP
#include "produto.h"

Produto::Produto(int codigo, const std::string &nome, double preco, Categoria categoria)
    : codigo(codigo), nome(nome), preco(preco), categoria(categoria) {}

int Produto::getCodigo() const {
    return codigo;
}

std::string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

std::string Produto::categoriaToString() const {
    switch(categoria) {
        case Categoria::ALIMENTO:   return "Alimento";
        case Categoria::BEBIDA:     return "Bebida";
        case Categoria::ELETRONICO: return "Eletronico";
        case Categoria::VESTUARIO:  return "Vestuario";
        case Categoria::LIVRO:      return "Livro";
        case Categoria::LIMPEZA:    return "Limpeza";
        default:                    return "Desconhecido";
    }
}