/*
 * BIRCH PROGRAMMING LANGUAGE v0.1.0, ALPHA
 *
 * THIS VERSION OF THE LANGUAGE IS STILL EXTREMELY INSTABLE AND
 * IS NOT AT ALL READY TO BE USED IN ANY PROJECTS OUTSIDE OF
 * TESTS.
 *
 * This file (and others) are likely to change drastically in a
 * short amount of time.
 */

// Standard library imports
#include <cstdlib>
#include <iostream>
#include <iterator>

// Local file imports
#include "chunk.hpp"
#include "common.hpp"
#include "vm.hpp"

static void repl(VM &vm) { 
    std::string line; 
    while (true) {
        std::cout << "> ";
        getline(std::cin, line);

        vm.interpret(line);

        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
    }
}

static std::string readFile(const std::string& path) {
    std::ifstream t(path);
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    return str;
}

int main() {
    return EXIT_SUCCESS;
}
