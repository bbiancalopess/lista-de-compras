#include "Item.hpp"
#include <iostream>

using std::cout;
using std::endl;

Item::Item(const int& id, const string& name, const double& price, const int& quantity) 
    : id(id), name(name), price(price), quantity(quantity) {}

int Item::getId() {
    return this->id;
}

double Item::getPrice() {
    return this->price;
}

int Item::getQuantity() {
    return this->quantity;
}

void Item::display() {
    cout <<  this->id << ". Item: " << this->name << ", Valor: " << this->price << ", Quantidade: " << this->quantity << endl;
}
