#include "ShoppingList.hpp"
#include <iostream>
#include "PersonalizedException.hpp"
#include "csv.hpp"
#include "PerishableItem.hpp"
#include <algorithm>

using std::to_string;
using std::remove_if;

ShoppingList::ShoppingList(){
    this->items = {}; // inicializa a lista como vazia
}

ShoppingList::~ShoppingList() {
    for (Item* item : items) { // itera pelos itens 
        delete item; // libera a memória de cada item
    }
}

void ShoppingList::addItem(Item* item) {
    try {
        vector<vector<string>> data = readCSV("../csv/items.csv");
        vector<string> new_item = {to_string(item->getId()), item->getName(), to_string(item->getPrice()), to_string(item->getQuantity()), "","1"};

        data.push_back(new_item);
        writeCSV("../csv/items.csv", data);
    } catch (const PersonalizedException& err) {
        throw PersonalizedException(err.what());
    }
    
    this->items.push_back(item);
}

void ShoppingList::addPerishableItem(PerishableItem* item) {
    try {
        vector<vector<string>> data = readCSV("../csv/items.csv");
        vector<string> new_item = {to_string(item->getId()), item->getName(), to_string(item->getPrice()), to_string(item->getQuantity()), item->getExpirationDate(), "2"};

        data.push_back(new_item);
        writeCSV("../csv/items.csv", data);
    } catch (const PersonalizedException& err) {
        throw PersonalizedException(err.what());
    }
    
    this->items.push_back(item);
}

double ShoppingList::displayItems() {
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
    bool found_vector = false;
    bool found_csv = false;

    try {
        vector<vector<string>> data = readCSV("../csv/items.csv");

        data.erase(
            remove_if(data.begin(), data.end(),
                        [&id, &found_csv](const vector<string>& item) {
                            if(item[0] == to_string(id)) {
                                found_csv = true;
                                return true;
                            } 
                            return false;
                        }),
            data.end()
        );
        writeCSV("../csv/items.csv", data);
    } catch (const PersonalizedException& err) {
        std::cout << "oi" << std::endl;
        throw PersonalizedException(err.what());
    }

    for (int i = 0; i < this->items.size(); i++) {
        if (this->items[i]->getId() == id) {
            this->items.erase(this->items.begin() + i); // remove o item da lista 
            found_vector = true;
            break; // sai do loop após encontrar e remover o item
        }  
    }
    if (!found_vector || !found_csv) throw PersonalizedException("------- ID do item não encontrado na lista ---------");
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