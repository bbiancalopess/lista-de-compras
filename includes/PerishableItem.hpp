#ifndef PERISHABLEITEM
#define PERISHABLEITEM

#include "Item.hpp"
#include <string>

using std::string;

class PerishableItem : public Item {
    private:
        string expirationDate;

    public:
        PerishableItem(const int& id, const string& name, const double& price, const int& quantity, const string& expirationDate);
        
        string getExpirationDate();
        void display() override;
};

#endif