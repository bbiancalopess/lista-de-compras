#include "ShoppingList.hpp"
#include <iostream>

ShoppingList::ShoppingList(){
    this->items = {};
}

ShoppingList::~ShoppingList() {
    for (Item* item : items) {
        delete item;
    }
}

void ShoppingList::addItem(Item* item) {
    this->items.push_back(item);
}

int ShoppingList::displayItems() {
    double spent_value = 0;
    if (this->items.size() == 0) std::cout << "Não há itens na lista." << std::endl;
    for (Item* item : this->items) {
        spent_value += item->getQuantity() * item->getPrice();
        item->display();
    }
    return spent_value;
    //std::cout << "Valor total gasto: " << spent_value << std::endl << std::endl;
}

void ShoppingList::removeItem(int id) {
    for (int i = 0; i < this->items.size(); i++) {
        if (this->items[i]->getId() == id) {
            this->items.erase(this->items.begin() + i);
        }
    }
}

int ShoppingList::getLastId() {
    for(Item* item : this->items) {
        std::cout << item->getId() << std::endl;
    }
    if(this->items.empty()){
        return 0;
    } else {
        return this->items[this->items.size() - 1]->getId();
    }    
}