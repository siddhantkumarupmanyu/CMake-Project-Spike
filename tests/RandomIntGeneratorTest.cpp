#include "RandomIntGenerator.hpp"
#include <catch2/catch.hpp>

TEST_CASE("generatesRandomInt") {
    auto intGenerator = RandomIntGenerator();
    auto randomInt1 = intGenerator.generate();

    auto randomInt2 = intGenerator.generate();

    REQUIRE(randomInt1 != randomInt2);
}