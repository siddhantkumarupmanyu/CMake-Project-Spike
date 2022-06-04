#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

TEST_CASE("Quick Test", "[main]") {
    auto intNum = 5;

    REQUIRE(intNum == 5);
}