#include "ShoppingList.hpp"
#include <iostream>

ShoppingList::~ShoppingList() {
    for (Item* item : items) {
        delete item;
    }
}

void ShoppingList::addItem(Item* item) {
    this->items.push_back(item);
}

void ShoppingList::displayItems() {
    for (Item* item : items) {
        item->display();
    }
}
