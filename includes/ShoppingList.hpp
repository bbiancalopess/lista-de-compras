#ifndef SHOPPINGLIST
#define SHOPPINGLIST

#include "Item.hpp"
#include <vector>

using std::vector;

class ShoppingList {
    private:
        vector<Item*> items;

    public:
        ShoppingList();
        ~ShoppingList();

        void addItem(Item* item);
        void removeItem(int id);
        int displayItems();
        int getLastId();
};

#endif 
