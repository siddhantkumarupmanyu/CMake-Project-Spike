#include "RandomIntGenerator.hpp"
#include <cstdlib>
#include <ctime>

RandomIntGenerator::RandomIntGenerator() { srand(time(0)); }

int RandomIntGenerator::generate() { return rand(); }