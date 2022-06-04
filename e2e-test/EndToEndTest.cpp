#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

std::string runApp();

TEST_CASE("generatesRandomNumber") {
    auto firstInvocation = runApp();
    auto secondInvocation = runApp();

    REQUIRE(secondInvocation != firstInvocation);
}

std::string runApp() {
    std::string cmd = "../src/app";
    std::array<char, 128> buffer;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"),
                                                  pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe.get())) {
        result += buffer.data();
    }
    return result;
}

// https://stackoverflow.com/a/478960