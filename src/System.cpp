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

void System::startTheSystem() {
    ShoppingList* shoppingList = new ShoppingList();

    while (true) {
        clearScreen(); 
        // exibe o menu de opções
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

        string choice = getInput("Escolha uma opção: ");
        
        if (choice == "5") { // se a escolha for 5 sai do loop e encerra o programa
            break;
        }
        
        clearScreen();
        
            if (choice == "1") {
                // adiciona um item não perecível
                cout << YELLOW << "------------------- Digite as informações do item -------------------------" << RESET << endl;
                cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
                string name = getInput("Digite o nome: ");
                if(name == "0") continue;
                string price = getInput("Digite o valor: ");
                if(price == "0") continue;
                string quantity = getInput("Digite a quantidade: ");
                if(quantity == "0") continue;
                Item* item;
                try {
                    item = new Item((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity));
                } catch (const PersonalizedException& err) {
                    cerr << RED << err.what() << RESET << endl;
                    cout << "------------- O item não foi inserido. -------------" << endl 
                        << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
                    cin.get();
                    continue;
                }
                cout << shoppingList->getLastId() << endl;
                shoppingList->addItem(item);
                clearScreen();
            } else if (choice == "2") {
                // adiciona um item perecível 
                cout << YELLOW << "---------------------- Digite as informações do item ----------------------" << RESET << endl;
                cout << "-- Você pode digitar '0' em qualquer momento para voltar ao menu de opções." << endl;
                string name = getInput("Digite o nome: ");
                if(name == "0") continue;
                string price = getInput("Digite o valor: ");
                if(price == "0") continue;
                string quantity = getInput("Digite a quantidade: ");
                if(quantity == "0") continue;
                string expirationDate = getInput("Digite a data de validade: ");
                if(expirationDate == "0") continue;
                PerishableItem* perishableItem;
                try {
                    perishableItem = new PerishableItem((shoppingList->getLastId() + 1), name, stod(price), stoi(quantity), expirationDate);
                } catch (const PersonalizedException& err) {
                    cerr << RED << err.what() << RESET << endl;
                    cout << "------------- O item não foi inserido. -------------" << endl 
                        << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
                    cin.get();
                    continue;
                }
                shoppingList->addItem(perishableItem);
                clearScreen();
            } else if (choice == "3") {
                // exibe todos os itens na lista de compras
                cout << YELLOW << "------------------------ ITENS ------------------------" << RESET << endl;
                int spent_value;
                try {
                    spent_value = shoppingList->displayItems();
                } catch (const PersonalizedException& err) {
                    cerr << RED << err.what() << RESET << endl;
                }
                cout << "Valor total gasto: " << spent_value << endl;
                cout << "-- Pressione ENTER para voltar para o menu de opções --" << endl;
                cin.get();
                clearScreen();
                
            } else if (choice == "4") {
                // remove um item da lista de compras pelo ID
                cout << YELLOW << "------------------ Qual item você deseja remover? -----------------" << RESET << endl;
                shoppingList->displayItems();
                int item_id = stoi(getInput("Escolha uma opção ou digite '0' para voltar para o menu de opções: "));
                if (item_id == 0) continue;
                try {
                    shoppingList->removeItem(item_id);
                } catch (const PersonalizedException& err) {
                    cerr << RED << err.what() << RESET << endl;
                    cout << "------------- O item não foi removido. -------------" << endl 
                        << "-- Pressione ENTER para voltar ao menu de opções. --" << endl;
                    cin.get();
                    continue;
                }
                clearScreen();
            } else {
                cout << "---------------- Opção inválida! ------------------" << endl;
            }
        
    }
    shoppingList->~ShoppingList();
}