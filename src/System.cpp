#include <iostream>
#include "System.hpp"
#include "ShoppingList.hpp"
#include <string>
#include "PerishableItem.hpp"
#include <stdexcept>
#include "PersonalizedException.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stod;
using std::stoi;
using std::invalid_argument;
using std::cerr;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */

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

void addItemInfo(ShoppingList* shoppingList) {
    cout << YELLOW << "------------------- Digite as informações do item -------------------------" << RESET << endl;
    cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
    string name = getInput("Digite o nome: ");
    if(name == "0") return;
    string price = getInput("Digite o valor: ");
    if(price == "0") return;
    string quantity = getInput("Digite a quantidade: ");
    if(quantity == "0") return;
    if(name == "" || price == "" || quantity == "") {
        cerr << RED << "----------- Nenhum campo pode ser vazio. -----------" << RESET << endl;
        cout << "------------- O item não foi inserido. -------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    }
    Item* item;
    try {
        item = new Item((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity));
    } catch (const PersonalizedException& err) {
        cerr << RED << err.what() << RESET << endl;
        cout << "------------- O item não foi inserido. -------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    }
    shoppingList->addItem(item);
    clearScreen();
}

void addPerishableItemInfo(ShoppingList* shoppingList) {
    cout << YELLOW << "---------------------- Digite as informações do item ----------------------" << RESET << endl;
    cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
    string name = getInput("Digite o nome: ");
    if(name == "0") return;
    string price = getInput("Digite o valor: ");
    if(price == "0") return;
    string quantity = getInput("Digite a quantidade: ");
    if(quantity == "0") return;
    string expirationDate = getInput("Digite a data de validade: ");
    if(expirationDate == "0") return;
    if(name == "" || price == "" || quantity == "" || expirationDate == "") {
        cerr << RED << "----------- Nenhum campo pode ser vazio. -----------" << RESET << endl;
        cout << "------------- O item não foi inserido. -------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    }
    PerishableItem* perishableItem;
    try {
        perishableItem = new PerishableItem((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity), expirationDate);
    } catch (const PersonalizedException& err) {
        cerr << RED << err.what() << RESET << endl;
        cout << "------------- O item não foi inserido. -------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    }
    shoppingList->addPerishableItem(perishableItem);
    clearScreen();
}

void showListItemsInfo(ShoppingList* shoppingList) {
    cout << YELLOW << "------------------------ ITENS ------------------------" << RESET << endl;
    double spent_value;
    try {
        spent_value = shoppingList->displayItems();
    } catch (const PersonalizedException& err) {
        cerr << RED << err.what() << RESET << endl;
        spent_value = 0;
    }
    cout << "Valor total gasto: R$" << spent_value << endl;
    cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
    cin.get();
    clearScreen();
}

void removeItemInfo(ShoppingList* shoppingList) {
    cout << YELLOW << "------------------ Qual item você deseja remover? -----------------" << RESET << endl;
    try {
        shoppingList->displayItems();
    } catch (const PersonalizedException& err) {
        cerr << RED << err.what() << RESET << endl;
        cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
        cin.get();
        return;
    }
    int item_id;
    try {
        item_id = stoi(getInput("Escolha uma opção ou digite '0' para voltar para o menu de opções: "));
    } catch (const invalid_argument& err) {
        cerr << RED << "------------------ Opção inválida. --------------------" << RESET << endl;
        cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
        cin.get();
        return;
    }
    
    if (item_id == 0 ) return;
    try {
        shoppingList->removeItem(item_id);
        cout << "--------------- O item foi removido. ---------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    } catch (const PersonalizedException& err) {
        cerr << RED << err.what() << RESET << endl;
        cout << "------------- O item não foi removido. -------------" << endl 
            << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
        cin.get();
        return;
    }
    clearScreen();
}

void showOptions() {
    cout << YELLOW
    << "-----------------------------------------------" << endl
    << "---------------LISTA DE COMPRAS----------------" << endl
    << "-----------------------------------------------" << RESET << endl
    << "------------------- OPÇÕES --------------------" << endl
    << "1. Adicionar item " << endl 
    << "2. Adicionar item perecível" << endl
    << "3. Visualizar itens" << endl
    << "4. Remover item" << endl
    << "5. Sair" << endl;
}

void System::startTheSystem() {
    ShoppingList* shoppingList = new ShoppingList();

    try {
        shoppingList->getAllItemsFromCSV();
    } catch (const PersonalizedException& err) {
        cout << RED 
        << err.what() << RESET << endl;
    }
    

    while (true) {
        clearScreen(); 
        showOptions(); // exibe o menu de opções
        
        string choice = getInput("Escolha uma opção: ");

        int choice_int;
        try {
            choice_int = stoi(choice);
        } catch (const invalid_argument& err) {
            continue;
        }

        clearScreen();

        switch(choice_int) {
            case 1:
                addItemInfo(shoppingList); // adiciona um item não perecível
                break;
            case 2:
                addPerishableItemInfo(shoppingList); // adiciona um item perecível 
                break;
            case 3:
                showListItemsInfo(shoppingList); // exibe todos os itens na lista de compras
                break;
            case 4:
                removeItemInfo(shoppingList); // remove um item da lista de compras pelo ID
                break;
            default:
                return;
                break;
        }        
    }
    shoppingList->~ShoppingList();
}