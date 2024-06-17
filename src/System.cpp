#include <iostream>
#include "System.hpp"
#include "ShoppingList.hpp"
#include <string>
#include "PerishableItem.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stod;
using std::stoi;

// obtem a entrada do usuário após exibir uma mensagem
string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls"); // comando para windows
    #else
        std::system("clear"); // comando para linux
    #endif
}

void System::startTheSystem() {
    ShoppingList* shoppingList = new ShoppingList();

    while (true) {
        clearScreen(); 
        // exibe o menu de opções
        cout << "-----------------------------------------------" << endl
             << "---------------LISTA DE COMPRAS----------------" << endl
             << "-----------------------------------------------" << endl
             << "------------------- OPÇÕES --------------------" << endl
             << "1. Adicionar item " << endl 
             << "2. Adicionar item perecível" << endl
             << "3. Visualizar itens" << endl
             << "4. Remover item" << endl
             << "5. Sair" << endl;

        string choice = getInput("Escolha uma opção: ");
        
        if (choice == "5") { // se a escolha for 5 sai do loop e encerra o programa
            break;
        }
        
        clearScreen();

        if (choice == "1") {
            // adiciona um item não perecível
            cout << "------------------- Digite as informações do item -------------------------" << endl;
            cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
            string name = getInput("Digite o nome: ");
            if(name == "0") continue;
            string price = getInput("Digite o valor: ");
            if(price == "0") continue;
            string quantity = getInput("Digite a quantidade: ");
            if(quantity == "0") continue;
            Item* item = new Item((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity));
            cout << shoppingList->getLastId() << endl;
            shoppingList->addItem(item);
            clearScreen();
        } else if (choice == "2") {
            // adiciona um item perecível 
            cout << "---------------------- Digite as informações do item ----------------------" << endl;
            cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
            string name = getInput("Digite o nome: ");
            if(name == "0") continue;
            string price = getInput("Digite o valor: ");
            if(price == "0") continue;
            string quantity = getInput("Digite a quantidade: ");
            if(quantity == "0") continue;
            string expirationDate = getInput("Digite a data de validade: ");
            if(expirationDate == "0") continue;
            PerishableItem* perishableItem = new PerishableItem((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity), expirationDate);
            shoppingList->addItem(perishableItem);
            clearScreen();
        } else if (choice == "3") {
            // exibe todos os itens na lista de compras
            cout << "------------------------ ITENS ------------------------" << endl;
            int spent_value = shoppingList->displayItems();
            cout << "Valor total gasto: " << spent_value << endl;
            cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
            cin.get();
            clearScreen();
            
        } else if (choice == "4") {
            // remove um item da lista de compras pelo ID
            cout << "------------------ Qual item você deseja remover? -----------------" << endl;
            shoppingList->displayItems();
            int item_id = stoi(getInput("Escolha uma opção ou digite '0' para voltar para o menu de opções: "));
            if (item_id == 0) continue;
            shoppingList->removeItem(item_id);
            clearScreen();
        } else {
            cout << "------------- Opção inválida! ------------------" << endl;
        }
    }
    shoppingList->~ShoppingList();
}