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

#include <fstream>
#include <iostream>

// These files don't exist yet, but will soon.
#include "compiler.hpp"
#include "scanner.hpp"
#include "vm.hpp"

namespace birch {
    // Also not sure if I like inlines yet, might remove this but it might be more performant???
    inline void repl() {
        while (true) {
            std::cout << "> ";
            std::string source;
            std::getline(std::cin, source);
            // Do something with that here later on
        }
    }

    inline void run_file(const std::string& filepath) {
        std::ifstream ifs(filepath);
        // Do something with stuff here later on
    }

    inline int main(int argc, char* argv[]) {
        if (argc == 1) {
            repl();
        } else if (argc == 2) {
            run_file(argv[1]);
        } else {
            fprintf(stderr, "Usage: birch [path]\n");
        }

        return 0;
    }
} // namespace birch

int main(int argc, char* argv[]) {
    return 0;
}
