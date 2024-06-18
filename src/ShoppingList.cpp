#include "ShoppingList.hpp"
#include <iostream>
#include "PersonalizedException.hpp"
#include "csv.hpp"
#include "PerishableItem.hpp"
#include <typeinfo>

ShoppingList::ShoppingList(){
    this->items = {}; // inicializa a lista como vazia
}

ShoppingList::~ShoppingList() {
    for (Item* item : items) { // itera pelos itens 
        delete item; // libera a memória de cada item
    }
}

void ShoppingList::addItem(Item* item) {
    this->items.push_back(item);
}

int ShoppingList::displayItems() {
    double spent_value = 0;
    if (this->items.empty()) // verifica se a lista está vazia
        throw PersonalizedException("Não há itens na lista."); 
    for (Item* item : this->items) {
        spent_value += item->getQuantity() * item->getPrice(); // incrementa o valor gasto
        item->display();
    }
    return spent_value;
}

void ShoppingList::removeItem(int id) {
    if (id <= 0) throw PersonalizedException("----------------- ID inválido --------------------");
    bool found = false;
    for (int i = 0; i < this->items.size(); i++) {
        if (this->items[i]->getId() == id) {
            this->items.erase(this->items.begin() + i); // remove o item da lista 
            found = true;
            break; // sai do loop após encontrar e remover o item
        }  
    }
    if (!found) throw PersonalizedException("------- ID do item não encontrado na lista ---------");
}

int ShoppingList::getLastId() {
    if(this->items.empty()) return 0; // retorna 0 se a lista estiver vazia
    else return this->items[this->items.size() - 1]->getId(); // retorna o id do último item
}

void ShoppingList::getAllItemsFromCSV() {
    vector<vector<string>> data = readCSV("../csv/items.csv");
    data.erase(data.begin()); // apaga a primeira linha da tabela, a linha dos títulos das colunas

    if(!data.empty()) {
        for (const auto& item : data) {
            int id = stoi(item[0]);
            string name = item[1];
            double price = stod(item[2]);
            int quantity = stoi(item[3]);
            string expiration_date = item[4];
            int item_type = stoi(item[5]);

            if (item_type == 1) {
                Item* new_item = new Item(id, name, price, quantity);
                this->items.push_back(new_item);
            } else if (item_type == 2) {
                Item* new_item = new PerishableItem(id, name, price, quantity, expiration_date);
                this->items.push_back(new_item);
            }
        }
    }
}