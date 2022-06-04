#include "RandomIntGenerator.hpp"

int RandomIntGenerator::generate() {
    if (lastNumber == 2) {
        lastNumber = 3;
        return lastNumber;
    } else {
        lastNumber = 2;
    }
    return lastNumber;
}