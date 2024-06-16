#include "PerishableItem.hpp"
#include <iostream>

using std::cout;
using std::endl;

PerishableItem::PerishableItem(const string& name, const double& price, const int& quantity, const string& expirationDate) 
    : Item(name, price, quantity), expirationDate(expirationDate) {}

string PerishableItem::getExpirationDate() {
    return expirationDate;
}

void PerishableItem::display() {
    cout << "Perishable Item: " << name << ", Price: " << price << ", Quantity: " << quantity 
              << ", Expiration Date: " << expirationDate << endl;
}
