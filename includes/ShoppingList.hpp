#ifndef SHOPPINGLIST
#define SHOPPINGLIST

#include "Item.hpp"
#include <vector>

using std::vector;

class ShoppingList {
    private:
        vector<Item*> items;

    public:
        ~ShoppingList();

        void addItem(Item* item);
        void displayItems();
};

#endif 
