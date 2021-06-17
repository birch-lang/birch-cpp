/*
 * This file gets CLI arguments.
 * It adheres to POSIX standards (as well as GNU, I think), simply
 * because windows sucks. I mean, because I was too lazy to look up
 * the Windows standards (and I didn't want to mess with DOS line
 * endings)
 *
 * Usage:
 *      
 *      birch::CliArguments args(argc, argv);
 *
 *      auto name = args.getOpt<std::string>("n", "name", "none");
 *      auto count = args.getOpt<int>("c", "count", -1);
 *
 *      auto version = args.getOpt("", "version");
 *      auto help = args.getOpt("h", "help");
 * 
 * Version 0.1.0
 */

// I was going to use #ifndef include guards but this is less typing :)
// I have other reasons as well, check out en.wikipedia.org/wiki/Pragma_once
#pragma once

// More stuff to include! There should be a system where you only have to
// include in one file (called `include.include` of course).
#include <cassert>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace birch
{
    class CliArguments {
    public:
        CliArguments(int argc, const char* const argv[]) : m_arguments(), m_value() {
      
            if (argc < 1) {
                throw std::invalid_argument("Invalid argc.");
            }

            if (argv == nullptr) {
                throw std::invalid_argument("Invalid argv.");
            }
      
            for (int i = 1; i < argc; ++i) {
                m_arguments.push_back(argv[i]);
            }
        }

        // Returns the remaining arguments
        const std::deque<std::string>& arguments() const { return m_arguments; }

        // Returns the value of long or short values if found, fallback value otherwise
        template <typename T> T getOpt(const std::string& opt, const std::string& longOpt, const T& fallback) {
            static_assert(! std::is_same<T, bool>::value, "Use bool specialization");

            if (opt.length() > 1) {
                throw std::invalid_argument("Short option can only have one character, dummy!.");
            }

            if (longOpt.length() == 1) {
                throw std::invalid_argument("Long option needs to be... longer!");
            }

            if (m_arguments.size() == 0) return fallback;

            if (! search(opt)) {
                if (! search(longOpt)) {
                    if (! searchCondensed(opt)) {
                        return fallback;
                    }
                }
            }

            T value;
            std::istringstream(m_value) >> value;
            return value;
        }

        bool getOpt(const std::string& opt, const std::string& longOpt) {
            if (opt.length() > 1) {
                throw std::invalid_argument("Short options can't be big, stoopid!");
            }

            if (longOpt.length() == 1) {
                throw std::invalid_argument("Long options can't be that small. Didn't you go to school?");
            }

            for (unsigned i = 0; i < m_arguments.size(); ++i) {
                std::string& arg = m_arguments.at(i);
                
                if (arg.size() < 2) continue;

                // condensed bool options -xyz
                if (opt.length() == 1 && arg[0] == '-' && arg[1] != '-') {
                    auto pos = arg.find(opt);
                    if (pos != std::string::npos) {
                        arg.erase(pos, 1);
                        if (arg == "-") {
                            m_arguments.erase(m_arguments.begin() + i);
                        }
                        return true;
                    }
                } else if (arg[0] == '-' && arg[1] == '-') {
                    if (arg.length() == 2) return false;

                    if (arg.substr(2) == longOpt) {
                        m_arguments.erase(m_arguments.begin() + i);
                        return true;
                    }
                }
            }
            return false;
        }

    private:

    };
}
