#include "Item.hpp"
#include <iostream>

using std::cout;
using std::endl;

Item::Item(const string& name, const double& price, const int& quantity) 
    : name(name), price(price), quantity(quantity) {}

string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

int Item::getQuantity() {
    return quantity;
}

void Item::display() {
    cout << "Item: " << name << ", Price: " << price << ", Quantity: " << quantity << endl;
}
