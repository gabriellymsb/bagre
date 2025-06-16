// MENU.H
#ifndef MENU_H
#define MENU_H

#include <vector>
#include "cliente.h"
#include "produto.h"
#include "pedido.h"

class Menu {
private:
    std::vector<Cliente*> clientes;
    std::vector<Produto> produtos;
    std::vector<Pedido*> pedidos;

    void inicializarDados(); // Para popular com dados de teste

    void cadastrarCliente();
    void cadastrarProduto();
    void cadastrarPedido();

    void listarClientes() const;
    void listarProdutos() const;
    void listarPedidos() const;

    Cliente* selecionarCliente();
    const Produto* selecionarProduto();

public:
    Menu();
    ~Menu(); // CRÍTICO: Para evitar vazamento de memória

    void executar();
};

#endif