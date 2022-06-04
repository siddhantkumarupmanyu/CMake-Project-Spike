#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

int main() {
    std::string cmd = "../src/app";
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"),
                                                  pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get())) {
        result += buffer.data();
    }

    std::cout << result << std::endl;

    return 0;
}


// https://stackoverflow.com/a/478960