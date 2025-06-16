// MENU.CPP
#include "menu.h"
#include <iostream>
#include <limits> // Para limpar o buffer de entrada

Menu::Menu() {
    inicializarDados();
}

// CRÍTICO: O destrutor libera toda a memória alocada dinamicamente.
Menu::~Menu() {
    for (Cliente* cli : clientes) {
        delete cli;
    }
    for (Pedido* ped : pedidos) {
        delete ped;
    }
    std::cout << "Sistema finalizado. Memoria liberada." << std::endl;
}

void Menu::inicializarDados() {
    // Adiciona alguns produtos de exemplo
    produtos.emplace_back(101, "Arroz 5kg", 25.50, Categoria::ALIMENTO);
    produtos.emplace_back(102, "Feijao 1kg", 8.90, Categoria::ALIMENTO);
    produtos.emplace_back(201, "Refrigerante 2L", 9.00, Categoria::BEBIDA);
    produtos.emplace_back(301, "Monitor 24pol", 899.99, Categoria::ELETRONICO);
}

void Menu::executar() {
    int opcao;
    do {
        std::cout << "\n===== SISTEMA DE PEDIDOS =====" << std::endl;
        std::cout << "1. Cadastrar Cliente" << std::endl;
        std::cout << "2. Cadastrar Produto" << std::endl;
        std::cout << "3. Criar Novo Pedido" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "4. Listar Clientes" << std::endl;
        std::cout << "5. Listar Produtos" << std::endl;
        std::cout << "6. Listar Pedidos" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        // Limpa o buffer de entrada para evitar problemas com getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: cadastrarProduto(); break;
            case 3: cadastrarPedido(); break;
            case 4: listarClientes(); break;
            case 5: listarProdutos(); break;
            case 6: listarPedidos(); break;
            case 0: break;
            default: std::cout << "Opcao invalida. Tente novamente." << std::endl; break;
        }
    } while (opcao != 0);
}

void Menu::cadastrarCliente() {
    int tipo;
    std::cout << "\n--- Cadastro de Cliente ---" << std::endl;
    std::cout << "Tipo (1-Fisico, 2-Juridico): ";
    std::cin >> tipo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    int codigo = clientes.size() + 1;
    std::string nome, doc;
    int rua, num;
    std::string bairro, cidade;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Endereco - Rua: ";
    std::cin >> rua;
    std::cout << "Endereco - Numero: ";
    std::cin >> num;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Endereco - Bairro: ";
    std::getline(std::cin, bairro);
    std::cout << "Endereco - Cidade: ";
    std::getline(std::cin, cidade);
    
    Endereco end(rua, num, bairro, cidade);

    if (tipo == 1) {
        std::cout << "CPF: ";
        std::getline(std::cin, doc);
        clientes.push_back(new ClienteFisico(codigo, nome, end, doc));
    } else if (tipo == 2) {
        std::cout << "CNPJ: ";
        std::getline(std::cin, doc);
        clientes.push_back(new ClienteJuridico(codigo, nome, end, doc));
    } else {
        std::cout << "Tipo invalido." << std::endl;
        return;
    }
    std::cout << "Cliente cadastrado com sucesso!" << std::endl;
}

void Menu::cadastrarProduto() {
    std::cout << "\n--- Cadastro de Novo Produto ---" << std::endl;
    
    std::string nome;
    double preco;
    int cat_opcao;
    Categoria categoriaSelecionada;

    // Gera um código simples. Em um sistema real, seria mais robusto.
    int codigo = produtos.empty() ? 401 : produtos.back().getCodigo() + 1;

    std::cout << "Nome do produto: ";
    std::getline(std::cin, nome);

    std::cout << "Preco do produto: ";
    std::cin >> preco;

    std::cout << "Selecione a Categoria:" << std::endl;
    std::cout << "1. Alimento | 2. Bebida | 3. Eletronico | 4. Vestuario | 5. Livro | 6. Limpeza" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> cat_opcao;

    switch (cat_opcao) {
        case 1: categoriaSelecionada = Categoria::ALIMENTO; break;
        case 2: categoriaSelecionada = Categoria::BEBIDA; break;
        case 3: categoriaSelecionada = Categoria::ELETRONICO; break;
        case 4: categoriaSelecionada = Categoria::VESTUARIO; break;
        case 5: categoriaSelecionada = Categoria::LIVRO; break;
        case 6: categoriaSelecionada = Categoria::LIMPEZA; break;
        default:
            std::cout << "Categoria invalida. Cadastro cancelado." << std::endl;
            return;
    }

    produtos.emplace_back(codigo, nome, preco, categoriaSelecionada);
    std::cout << "Produto '" << nome << "' cadastrado com sucesso! Codigo: " << codigo << std::endl;
}

void Menu::cadastrarPedido() {
    std::cout << "\n--- Criacao de Pedido ---" << std::endl;
    Cliente* clienteSelecionado = selecionarCliente();
    if (!clienteSelecionado) {
        std::cout << "Criacao de pedido cancelada." << std::endl;
        return;
    }

    Pedido* novoPedido = new Pedido(clienteSelecionado);
    int op;
    do {
        const Produto* produtoSelecionado = selecionarProduto();
        if (produtoSelecionado) {
            int qtd;
            std::cout << "Quantidade: ";
            std::cin >> qtd;
            novoPedido->adicionarItem(Item(produtoSelecionado, qtd));
            std::cout << "Item adicionado!" << std::endl;
        }
        std::cout << "Adicionar outro item? (1-Sim, 0-Nao): ";
        std::cin >> op;
    } while (op == 1);

    pedidos.push_back(novoPedido);
    std::cout << "\nPedido finalizado e registrado com sucesso!" << std::endl;
    novoPedido->exibirPedido();
}


void Menu::listarClientes() const {
    std::cout << "\n--- Lista de Clientes ---" << std::endl;
    if (clientes.empty()) {
        std::cout << "Nenhum cliente cadastrado." << std::endl;
        return;
    }
    for (const auto* cli : clientes) {
        cli->mostrarDados();
        std::cout << "-------------------------" << std::endl;
    }
}

void Menu::listarProdutos() const {
    std::cout << "\n--- Catalogo de Produtos ---" << std::endl;
    if (produtos.empty()) {
        std::cout << "Nenhum produto cadastrado." << std::endl;
        return;
    }
    for (const auto& prod : produtos) {
        std::cout << "Cod: " << prod.getCodigo() << " | " << prod.getNome()
                  << " | R$ " << prod.getPreco() << " | Cat: " << prod.categoriaToString() << std::endl;
    }
}

void Menu::listarPedidos() const {
    std::cout << "\n\n<<<<<<<<<< HISTORICO GERAL DE PEDIDOS >>>>>>>>>>" << std::endl;
    if (pedidos.empty()) {
        std::cout << "Nenhum pedido registrado." << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;
        return;
    }

    double totalGeral = 0.0;
    for (const auto& ped : pedidos) {
        ped->exibirPedido(); // Este método já exibe o total individual do pedido
        totalGeral += ped->getValorFinal();
    }

    std::cout << "==============================================" << std::endl;
    std::cout << "      >>> VALOR TOTAL DE TODOS OS PEDIDOS: R$ " 
              << std::fixed << std::setprecision(2) << totalGeral << " <<<" << std::endl;
    std::cout << "==============================================\n" << std::endl;
}

Cliente* Menu::selecionarCliente() {
    if (clientes.empty()) {
        std::cout << "Nao ha clientes cadastrados. Cadastre um cliente primeiro." << std::endl;
        return nullptr;
    }
    std::cout << "Selecione um cliente pelo codigo:" << std::endl;
    listarClientes();
    int codigo;
    std::cout << "Digite o codigo do cliente: ";
    std::cin >> codigo;
    for (auto* cli : clientes) {
        if (cli->getCodigo() == codigo) {
            return cli;
        }
    }
    std::cout << "Cliente nao encontrado." << std::endl;
    return nullptr;
}

const Produto* Menu::selecionarProduto() {
    if (produtos.empty()) {
        std::cout << "Nao ha produtos cadastrados." << std::endl;
        return nullptr;
    }
    std::cout << "Selecione um produto pelo codigo:" << std::endl;
    listarProdutos();
    int codigo;
    std::cout << "Digite o codigo do produto: ";
    std::cin >> codigo;
    for (const auto& prod : produtos) {
        if (prod.getCodigo() == codigo) {
            return &prod;
        }
    }
    std::cout << "Produto nao encontrado." << std::endl;
    return nullptr;
}