//PEDIDO.CPP
#include "pedido.h"
#include <iostream>
#include <iomanip> // Para formatar a saída

int Pedido::proximoNumero = 1;

Pedido::Pedido(Cliente* cli) : cliente(cli) {
    numero = proximoNumero++;
}

int Pedido::getNumero() const {
    return numero;
}

Cliente* Pedido::getCliente() const {
    return cliente;
}

void Pedido::adicionarItem(const Item& novoItem) {
    for (auto& item : itens) {
        if (item.getProduto()->getCodigo() == novoItem.getProduto()->getCodigo()) {
            item.adicionarQuantidade(novoItem.getQuantidade());
            return;
        }
    }
    itens.push_back(novoItem);
}

double Pedido::getSubtotal() const {
    double total = 0.0;
    for (const auto& item : itens) {
        total += item.getValorTotal();
    }
    return total;
}

double Pedido::getValorDesconto() const {
    if (cliente) {
        return getSubtotal() * cliente->getTaxaDesconto();
    }
    return 0.0;
}

double Pedido::getValorFinal() const {
    return getSubtotal() - getValorDesconto();
}

void Pedido::exibirPedido() const {
    std::cout << "\n================ PEDIDO N " << numero << " ================" << std::endl;
    if (cliente) {
        cliente->mostrarDados();
    }
    
    std::cout << "\n--- Itens ---" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& item : itens) {
        std::cout << "  - Prod: " << item.getProduto()->getNome()
                  << " | Qtd: " << item.getQuantidade()
                  << " | Preco Unit: R$ " << item.getProduto()->getPreco()
                  << " | Subtotal: R$ " << item.getValorTotal() << std::endl;
    }

    std::cout << "\n--- Resumo Financeiro ---" << std::endl;
    std::cout << "  Subtotal Bruto....: R$ " << getSubtotal() << std::endl;
    std::cout << "  Desconto Aplicado.: R$ " << getValorDesconto() << std::endl;
    std::cout << "  VALOR TOTAL.......: R$ " << getValorFinal() << std::endl;
    std::cout << "==============================================" << std::endl;
}