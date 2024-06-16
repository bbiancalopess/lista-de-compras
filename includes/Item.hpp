#ifndef ITEM
#define ITEM

#include <string>

using std::string;

class Item {
    protected:
        int id;
        string name;
        double price;
        int quantity;

    public:
        Item(const int& id, const string& name, const double& price, const int& quantity);
        virtual ~Item() = default;

        int getId();
        string getName();
        double getPrice();
        int getQuantity();

        virtual void display();
};

#endif
