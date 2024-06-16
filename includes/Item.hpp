#ifndef ITEM
#define ITEM

#include <string>

using std::string;

class Item {
    protected:
        string name;
        double price;
        int quantity;

    public:
        Item(const string& name, const double& price, const int& quantity);
        virtual ~Item() = default;

        string getName();
        double getPrice();
        int getQuantity();

        virtual void display();
};

#endif
