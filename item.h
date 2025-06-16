// ITEM.H
#ifndef ITEM_H
#define ITEM_H

#include "produto.h"

class Item {
private:
    const Produto* produto; // CORREÇÃO: Usar ponteiro para não copiar o objeto inteiro.
    int quantidade;

public:
    // CORREÇÃO: O item deve apontar para um produto existente.
    Item(const Produto* prod, int qtd);

    const Produto* getProduto() const;
    int getQuantidade() const;

    // CORREÇÃO: O valor total deve ser calculado sob demanda para evitar inconsistência.
    double getValorTotal() const; 

    void adicionarQuantidade(int quantidadeAdicional);
};

#endif