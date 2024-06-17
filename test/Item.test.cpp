#include "Catch2.hpp"
#include "Item.hpp"
#include "PersonalizedException.hpp"



TEST_CASE("Should get right ids", "[Item]") {
    Item item1(1, "Item 1", 10.0, 3);
    Item item2(2, "Item 2", 20.0, 4);
    Item item3(3, "Item 3", 30.0, 5);

    REQUIRE(item1.getId() == 1);
    REQUIRE(item2.getId() == 2);
    REQUIRE(item3.getId() == 3);
}

TEST_CASE("Should get right prices", "[Item]") {
    Item item4(1, "Item 1", 10.0, 3);
    Item item5(2, "Item 2", 20.0, 4);
    Item item6(3, "Item 3", 30.0, 5);
    
    REQUIRE(item4.getPrice() == 10.0);
    REQUIRE(item5.getPrice() == 20.0);
    REQUIRE(item6.getPrice() == 30.0);
}

TEST_CASE("Should get right quantitys", "[Item]") {
    Item item7(1, "Item 1", 10.0, 3);
    Item item8(2, "Item 2", 20.0, 4);
    Item item9(3, "Item 3", 30.0, 5);

    REQUIRE(item7.getQuantity() == 3);
    REQUIRE(item8.getQuantity() == 4);
    REQUIRE(item9.getQuantity() == 5);
}

TEST_CASE("Should throw personalized exception", "[Item]") {
    REQUIRE_THROWS_AS(Item(4, "Item 4", -5.90, 2), PersonalizedException);
    REQUIRE_THROWS_AS(Item(5, "Item 5", -6.90, 3), PersonalizedException);
    REQUIRE_THROWS_AS(Item(6, "Item 5", -7.90, 4), PersonalizedException);
    
    REQUIRE_THROWS_AS(Item(4, "Item 4", 48.26, -2), PersonalizedException);
    REQUIRE_THROWS_AS(Item(5, "Item 5", 16.12, -3), PersonalizedException);
    REQUIRE_THROWS_AS(Item(6, "Item 5", 15.45, -4), PersonalizedException);
}