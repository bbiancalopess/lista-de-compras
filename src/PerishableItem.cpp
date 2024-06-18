#include "PerishableItem.hpp"
#include <iostream>

using std::cout;
using std::endl;

PerishableItem::PerishableItem(const int& id, const string& name, const double& price, const int& quantity, const string& expiration_date) 
    : Item(id, name, price, quantity), expiration_date(expiration_date) {}

void PerishableItem::display() {
    cout << this->id << ". Item perecível: " << this->name << ", Valor: R$" << this->price << ", Quantidade: " << this->quantity 
              << ", Data de validade: " << this->expiration_date << endl;
}

string PerishableItem::getExpirationDate() {
    return this->expiration_date;
}