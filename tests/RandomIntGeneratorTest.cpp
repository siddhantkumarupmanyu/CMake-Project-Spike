#include "RandomIntGenerator.hpp"
#include <catch2/catch.hpp>

TEST_CASE("generatesRandomIntOnGenerate") {
    auto intGenerator = RandomIntGenerator();
    auto randomInt1 = intGenerator.generate();

    auto randomInt2 = intGenerator.generate();

    REQUIRE(randomInt1 != randomInt2);
}

TEST_CASE("generatesRandomIntForDifferentInstances") {
    auto generator1 = RandomIntGenerator();
    auto generator2 = RandomIntGenerator();

    REQUIRE(generator1.generate() != generator2.generate());
}