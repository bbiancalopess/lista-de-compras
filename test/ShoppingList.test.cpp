#include "Catch2.hpp"
#include "ShoppingList.hpp"
#include "Item.hpp"

TEST_CASE("Should return right last id", "[ShoppingList]") {
    Item item1(1, "Item 1", 10.0, 2);
    Item item2(2, "Item 2", 20.0, 3);
    Item item3(3, "Item 3", 5.50, 4);

    ShoppingList shoppingList;

    REQUIRE(shoppingList.getLastId() == 0);
    shoppingList.addItem(&item1);
    REQUIRE(shoppingList.getLastId() == 1);
    shoppingList.addItem(&item2);
    REQUIRE(shoppingList.getLastId() == 2);
    shoppingList.addItem(&item3);
    REQUIRE(shoppingList.getLastId() == 3);
}

TEST_CASE("Should return right spent value", "[ShoppingList]") {
    Item item4(1, "Item 1", 10.0, 2);
    Item item5(2, "Item 2", 20.0, 3);
    Item item6(3, "Item 3", 5.50, 4);

    ShoppingList shoppingList;
    
    REQUIRE(shoppingList.displayItems() == 0);
    shoppingList.addItem(&item4);
    REQUIRE(shoppingList.displayItems() == 20);
    shoppingList.addItem(&item5);
    REQUIRE(shoppingList.displayItems() == 80);
    shoppingList.addItem(&item6);
    REQUIRE(shoppingList.displayItems() == 102);
}

TEST_CASE("Should remove items", "[ShoppingList]") {
    Item item7(1, "Item 1", 10.0, 2);
    Item item8(2, "Item 2", 20.0, 3);
    Item item9(3, "Item 3", 5.50, 4);

    ShoppingList shoppingList;

    REQUIRE(shoppingList.displayItems() == 0);
    REQUIRE(shoppingList.getLastId() == 0);
    shoppingList.addItem(&item7);
    REQUIRE(shoppingList.getLastId() == 1);
    REQUIRE(shoppingList.displayItems() == 20);
    shoppingList.addItem(&item9);
    REQUIRE(shoppingList.getLastId() == 2);
    REQUIRE(shoppingList.displayItems() == 80);
    shoppingList.addItem(&item9);
    REQUIRE(shoppingList.getLastId() == 3);
    REQUIRE(shoppingList.displayItems() == 102);
    
    shoppingList.removeItem(3);
    REQUIRE(shoppingList.getLastId() == 2);
    REQUIRE(shoppingList.displayItems() == 80);
    shoppingList.removeItem(1);
    REQUIRE(shoppingList.getLastId() == 2);
    REQUIRE(shoppingList.displayItems() == 60);
    shoppingList.removeItem(2);
    REQUIRE(shoppingList.getLastId() == 0);
    REQUIRE(shoppingList.displayItems() == 0);
}