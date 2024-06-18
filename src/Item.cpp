#include "Item.hpp"
#include <iostream>
#include <stdexcept>
#include "PersonalizedException.hpp"

using std::cout;
using std::endl;
using std::invalid_argument;

Item::Item(const int& id, const string& name, const double& price, const int& quantity) 
    : id(id), name(name), price(price), quantity(quantity) {
        if (price < 0) {
            throw PersonalizedException("----------- Preço não pode ser negativo. -----------");
        }
        if (quantity < 0) {
            throw PersonalizedException("--------- Quantidade não pode ser negativa. --------");
        }
    }

int Item::getId() {
    return this->id;
}

double Item::getPrice() {
    return this->price;
}

int Item::getQuantity() {
    return this->quantity;
}

string Item::getName() {
    return this->name;
}

void Item::display() {
    cout <<  this->id << ". Item: " << this->name << ", Valor: R$" << this->price << ", Quantidade: " << this->quantity << endl;
}
