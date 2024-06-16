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

string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void getTitle() {
    cout << "-----------------------------------------------" << endl
        << "---------------LISTA DE COMPRAS----------------" << endl
        << "-----------------------------------------------" << endl;
}

void System::startTheSystem() {
    ShoppingList* shoppingList = new ShoppingList();

    while (true) {
        begining:
        clearScreen();
        getTitle();
        cout << "------------------- OPÇÕES --------------------" << endl
             << "1. Adicionar item " << endl 
             << "2. Adicionar item perecível" << endl
             << "3. Visualizar itens" << endl
             << "4. Remover item" << endl
             << "5. Sair" << endl;
        string choice = getInput("Escolha uma opção: ");
        clearScreen();

        if (choice == "5") {
            break;
        }
        
        if (choice == "1") {
            cout << "------------------- Digite as informações do item -------------------------" << endl;
            cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
            string name = getInput("Digite o nome: ");
            if(name == "0") goto begining;
            string price = getInput("Digite o valor: ");
            if(price == "0") goto begining;
            string quantity = getInput("Digite a quantidade: ");
            if(quantity == "0") goto begining;
            Item* item = new Item((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity));
            cout << shoppingList->getLastId() << endl;
            shoppingList->addItem(item);
            clearScreen();
        } else if (choice == "2") {
            cout << "---------------------- Digite as informações do item ----------------------" << endl;
            cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
            string name = getInput("Digite o nome: ");
            if(name == "0") goto begining;
            string price = getInput("Digite o valor: ");
            if(price == "0") goto begining;
            string quantity = getInput("Digite a quantidade: ");
            if(quantity == "0") goto begining;
            string expirationDate = getInput("Digite a data de validade: ");
            if(expirationDate == "0") goto begining;
            PerishableItem* perishableItem = new PerishableItem((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity), expirationDate);
            shoppingList->addItem(perishableItem);
            clearScreen();
        } else if (choice == "3") {
            cout << "------------------------ ITENS ------------------------" << endl;
            int spent_value = shoppingList->displayItems();
            cout << "Valor total gasto: " << spent_value << endl;
            cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
            cin.get();
            clearScreen();
            
        } else if (choice == "4") {
            cout << "------------------ Qual item você deseja remover? -----------------" << endl;
            shoppingList->displayItems();
            int item_id = stoi(getInput("Escolha uma opção ou digite '0' para voltar para o menu de opções: "));
            if (item_id == 0) goto begining;
            shoppingList->removeItem(item_id);
            clearScreen();
        } else {
            cout << "------------- Opção inválida! ------------------" << endl;
        }
    }
    shoppingList->~ShoppingList();
}