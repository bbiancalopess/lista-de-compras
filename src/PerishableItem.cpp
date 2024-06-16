#include "PerishableItem.hpp"
#include <iostream>

using std::cout;
using std::endl;

PerishableItem::PerishableItem(const int& id, const string& name, const double& price, const int& quantity, const string& expirationDate) 
    : Item(id, name, price, quantity), expirationDate(expirationDate) {}

string PerishableItem::getExpirationDate() {
    return expirationDate;
}

void PerishableItem::display() {
    cout << this->id << ". Item perecível: " << this->name << ", Valor: " << this->price << ", Quantidade: " << this->quantity 
              << ", Data de validade: " << this->expirationDate << endl;
}
