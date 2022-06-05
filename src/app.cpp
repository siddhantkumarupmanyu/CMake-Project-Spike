#include "RandomIntGenerator.hpp"
#include <iostream>

int main() {
    auto intGenerator = RandomIntGenerator();
    auto randomInt = intGenerator.generate();

    std::cout << randomInt << std::endl;

    return 0;
}