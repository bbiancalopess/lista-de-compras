#include "Catch2.hpp"
#include "csv.hpp"
#include "PersonalizedException.hpp"

TEST_CASE("Should throw PersonalizedException", "[csv]") {
    vector<vector<string>> data = {{}};
    REQUIRE_THROWS_AS(writeCSV("csvTestError.csv", data), PersonalizedException);
    REQUIRE_THROWS_AS(readCSV("csvTestError.csv"), PersonalizedException);
}

TEST_CASE("Shouldn't throw any exception", "[csv]") {
    vector<vector<string>> data = {{}};
    REQUIRE_NOTHROW(writeCSV("csvTest.csv", data));
    REQUIRE_NOTHROW(readCSV("csvTest.csv"));
}