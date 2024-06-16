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

void System::startTheSystem() {
    ShoppingList* shoppingList;

    while (true) {
        cout << "1. Add Item\n2. Add Perishable Item\n3. Display Items\n4. Exit\nChoose an option: ";
        string choice = getInput("Choose an option: ");

        if (choice == "4") {
            break;
        }

        string name = getInput("Enter name: ");
        string price = getInput("Enter price: ");
        string quantity = getInput("Enter quantity: ");
        
        if (choice == "1") {
            cout << "1" << endl;
            Item* item = new Item(name, stod(price), stoi(quantity));
            cout << "2" << endl;
            shoppingList->addItem(item);
            cout << "3" << endl;
        } else if (choice == "2") {
            string expirationDate = getInput("Enter expiration date: ");
            PerishableItem* perishableItem = new PerishableItem(name, stod(price), stoi(quantity), expirationDate);
            shoppingList->addItem(perishableItem);
        } else if (choice == "3") {
            shoppingList->displayItems();
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    shoppingList->displayItems();
}