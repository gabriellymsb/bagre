//ITEM.CPP
#include "item.h"

Item::Item(const Produto* prod, int qtd)
    : produto(prod), quantidade(qtd) {}

const Produto*Item::getProduto() const {
    return produto;
}

int Item::getQuantidade() const {
    return quantidade;
}

// O valor é calculado aqui, garantindo que esteja sempre correto.
double Item::getValorTotal() const {
    if (produto) {
        return produto->getPreco() * quantidade;
    }
    return 0.0;
}

void Item::adicionarQuantidade(int quantidadeAdicional) {
    if (quantidadeAdicional > 0) {
        this->quantidade += quantidadeAdicional;
    }
}