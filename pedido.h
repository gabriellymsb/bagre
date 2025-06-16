// PEDIDO.H
#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "item.h"
#include "cliente.h"

class Pedido {
private:
    static int proximoNumero;
    int numero;
    Cliente* cliente;
    std::vector<Item> itens;

public:
    Pedido(Cliente* cli);

    int getNumero() const;
    Cliente* getCliente() const;
    void adicionarItem(const Item& novoItem);
    
    double getSubtotal() const;
    double getValorDesconto() const;
    double getValorFinal() const;
    
    void exibirPedido() const;
};

#endif