# Lista de Compras em C++

Este é um projeto simples de uma aplicação de lista de compras em C++, utilizando conceitos de programação orientada a objetos. A aplicação permite adicionar itens simples e itens perecíveis, exibir a lista de itens, remover itens e calcular o valor total gasto.

## Funcionalidades

- Adicionar item simples à lista de compras.
- Adicionar item perecível à lista de compras (com data de validade).
- Exibir lista de itens e valor total gasto.
- Remover itens da lista.


## Estrutura do Projeto

projeto-lista-compras-cpp/

│

├── includes/                           # Pasta contendo os .hpp do projeto

│ ├── Item.hpp                          # Declaração da classe Item

│ ├── PerishableItem.hpp                # Declaração da classe PerishableItem

│ ├── PersonalizedException.hpp         # Declaração da classe PersonalizedException

│ ├── ShoppingList.hpp                  # Declaração da classe ShoppingList

│ └── System.hpp                        # Declaração da classe System

│

├── principal/   

│ └── main.cpp                          # Inicialização do programa

│

├── src/                                # Pasta contendo os .cpp do projeto

│ ├── Item.cpp                          # Implementação da classe Item

│ ├── PerishableItem.cpp                # Implementação da classe PerishableItem

│ ├── PersonalizedException.cpp         # Implementação da classe PersonalizedException

│ ├── ShoppingList.cpp                  # Implementação da classe ShoppingList

│ └── System.cpp                        # Declaração da classe System

│

├── test/

│ ├── Catch2.hpp                        # Biblioteca Catch2 

│ ├── CMakesLists.txt                   # Configuração do CMake para rodar os testes 

│ ├── Item.test.cpp                     # Testes para a classe Item

│ ├── ShoppingList.test.cpp             # Testes para a classe ShoppingList

│ └── test.cpp                          # Criação automática da main para os testes

│

├── .gitignore                          # Define as extensões que o git deve ignorar

├── CMakesLists.txt                     # Configuração do CMake para rodar o programa

└── README.md                           # Este arquivo


## Como Compilar e Executar

1. **Compilação:**

   - Caso não tenha o WSL, instale-o e configure-o
   - Após isso, acesse o WSL no diretório do projeto
   - Então execute os seguintes comandos:
    ```wsl
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

2. **Execução:**
   - Para executar rode o executável gerado na compilação com o comando
    ```wsl
    $ ./lista_de_compra

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir pull requests para correções de bugs, melhorias de código, ou novas funcionalidades.